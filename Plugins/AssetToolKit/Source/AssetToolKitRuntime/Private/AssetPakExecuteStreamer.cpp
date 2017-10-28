#include "AssetToolKitRuntimePrivatePCH.h"
#include "FileManagerGeneric.h"
#include "StaticMeshAssetActor.h"
#include "AssetPakExecuteStreamer.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

#define IS_PROGRAM 1


FAssetPakExecuteStreamer::FAssetPakExecuteStreamer()
	: PakPlatform(new FPakPlatformFile())
{

}

FAssetPakExecuteStreamer::~FAssetPakExecuteStreamer()
{
}

bool FAssetPakExecuteStreamer::Initialize(FStreamableManager* mStreamableManager)
{
	check(mStreamableManager);
	if (!bInitialized)
	{
		//if (GConfig->GetBool(TEXT("AssetStreamer"), TEXT("bSigned"), bSigned, GEngineIni))
		//{
		//	bSigned = false;
		//}
		bSigned = false;
		LocalPlatformFile = &FPlatformFileManager::Get().GetPlatformFile();
		//if (LocalPlatformFile != nullptr)
		//{
		//	IPlatformFile* PakPlatformFile = FPlatformFileManager::Get().GetPlatformFile(TEXT("PakFile"));
		//	IPlatformFile* NetPlatformFile = FPlatformFileManager::Get().GetPlatformFile(TEXT("NetworkFile"));
		//	if (PakPlatformFile != nullptr && NetPlatformFile != nullptr)
		//	{
		//		if (NetPlatform.IsValid()) 
		//		{
		//			bInitialized = NetPlatform->Initialize(LocalPlatformFile, *FString::Printf(TEXT("-FileHostIp=%s"), *serverhos)
		//		}
		//	}
		//}
		bInitialized = 1;
	}
	 
	this->StreamableManager = mStreamableManager;
	return bInitialized;
}

bool FAssetPakExecuteStreamer::StreamPackage(const FString& PakFileName, IAssetStreamerListener* AssetStreamerListener, const TCHAR* CmdLine)
{
	Lock();
	Listener = NULL;
	LocalPlatformFile = &FPlatformFileManager::Get().GetPlatformFile();
	if (PakPlatform.IsValid())
	{
		PakPlatform->Initialize(LocalPlatformFile, TEXT(""));
	}

	FPlatformFileManager::Get().SetPlatformFile(*PakPlatform);

	const FString FilePath = GetResolveLocalPath(PakFileName);
//	FPakFile PakFile(*FilePath, bSigned);
	FPakFile PakFile(LocalPlatformFile, *FilePath, bSigned);
	if (!PakFile.IsValid())
	{
		Unlock();
		return false;
	}

	PakFile.SetMountPoint(*FPaths::EngineContentDir());
	const int32 PakOrder = 0;
	if (!PakPlatform->Mount(*FilePath, PakOrder, *FPaths::EngineContentDir()))
	{
		Unlock();
		return false;
	}
	TSet<FString> FileList;
	PakFile.FindFilesAtPath(FileList, *PakFile.GetMountPoint(), true, false, true);
	StreamedAssets.Empty();

	for (TSet<FString>::TConstIterator FileItem(FileList); FileItem; ++FileItem)
	{
		FString AssetName = *FileItem;
		if (AssetName.EndsWith(FPackageName::GetAssetPackageExtension()) ||
			AssetName.EndsWith(FPackageName::GetMapPackageExtension()))
		{
			//assetName 路径 是“../../../Engine/Content/File.uasset”
			//但是需要加载的路径是“/Game/File.File”
			//经过多轮测试的结果 ( 注明：实际上/Game/File.File也是不行的)
			int32 tindex = UKismetStringLibrary::FindSubstring(AssetName, "/", false, true, AssetName.Len() - 1);

			int32 endindex = UKismetStringLibrary::FindSubstring(AssetName, ".", false, true, AssetName.Len() - 1);

			AssetName = UKismetStringLibrary::GetSubstring(AssetName, tindex + 1, endindex - tindex - 1);

			AssetName = "/Engine/" + AssetName + "." + AssetName;

			FStringAssetReference tt = AssetName;

			tt.SetPath(AssetName);

			StreamedAssets.Add(AssetName);
		}

	}
	Listener = AssetStreamerListener;
	if (Listener)
	{
		Listener->OnPrepareAssetStreaming(StreamedAssets);
	}
	if (StreamableManager == nullptr)
	{
		Unlock();
		return false;
	}
	FStringAssetReference AssetToLoad = StreamedAssets[0];

	//FString ts1 = AssetToLoad.ToString();

	//int32 tindex = UKismetStringLibrary::FindSubstring(ts1, "/", false, true, ts1.Len() - 1);

	//int32 endindex = UKismetStringLibrary::FindSubstring(ts1, ".", false, true, ts1.Len() - 1);

	//ts1 = UKismetStringLibrary::GetSubstring(ts1, tindex+1, endindex - tindex - 1);

	//ts1 = "/Game/" + ts1 + "." + ts1;

	//AssetToLoad.SetPath(ts1);

	//UObject* AssetObject = AssetToLoad.ResolveObject();

//	+AssetLongPathname	L"/Engine/Pillar_50x500.Pillar_50x500"	FString

	FStringAssetReference AssetRef(TEXT("/Engine/Pillar_50x500.Pillar_50x500"));

	UObject* AssetObject1 = StreamableManager->SynchronousLoad(AssetToLoad);

	UE_LOG(LogPackage, Error, TEXT("Pak Uobject :  %s"), *AssetObject1->GetFullName());

	UObject* AssetObject = AssetRef.TryLoad();

	//FString ts = AssetToLoad.ToString();
	//UStaticMesh* test = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, *ts));

	//FActorSpawnParameters SpawnInfo;
	//SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	//FVector loc = UKismetMathLibrary::RandomPointInBoundingBox(FVector::ZeroVector, FVector(20000, 20000, 20000));
	//FTransform FTPoint(FRotator::ZeroRotator, loc);
	//AStaticMeshAssetActor* test = GEngine->GetWorld()->SpawnActor<AStaticMeshAssetActor>(AStaticMeshAssetActor::StaticClass(), FTPoint, SpawnInfo);
	//test->LoadStaticMeshAsset(AssetObject1, 0);

	UAssetExecutePakFile::GetSceneAssetMan()->InstanceAssetToLevel(AssetObject1, 0);

	//StreamableManager->RequestAsyncLoad(StreamedAssets, FStreamableDelegate::CreateRaw(this, &FAssetPakExecuteStreamer::OnStreamingCompleteDelegate));
	return true;
}


FString FAssetPakExecuteStreamer::GetResolveLocalPath(const FString& FileName)
{
	return TEXT("F:/UE4Work/BuildSlatePlugin/Content/") + FileName + TEXT(".pak");
}

void FAssetPakExecuteStreamer::OnStreamingCompleteDelegate()
{
	if (Listener != NULL)
	{
		Listener->OnAssetStreamComplete();
		Listener = NULL;
	}
	Unlock();
}


#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif