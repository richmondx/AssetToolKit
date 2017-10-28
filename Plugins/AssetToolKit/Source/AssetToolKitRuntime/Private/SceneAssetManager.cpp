// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetToolKitRuntimePrivatePCH.h"
#include "GameSingleton.h"
//#include "ItemInfoDataBase.h"
#include "SceneAssetManager.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif


// Sets default values
ASceneAssetManager::ASceneAssetManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASceneAssetManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASceneAssetManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	timeload += DeltaTime;
}

void ASceneAssetManager::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//加载资源对象表
	LoadMeshesDataBase = Cast<UAssetDataBase>(StaticLoadObject(UDataAsset::StaticClass(), NULL, *AssetDataPath, NULL, LOAD_None, NULL));
	//LoadSceneAsset(0);
}

bool ASceneAssetManager::LoadSceneAsset(int32 Id)
{
	Index = Id;
	if (LoadMeshesDataBase != NULL && LoadMeshesDataBase->MeshList.Num() >= Id)
	{
		AllAssetNum = LoadMeshesDataBase->MeshList.Num();
		TArray<FStringAssetReference> ObjToLoad;
		FStreamableManager& BaseLoader = UGameSingleton::Get().AssetLoader;
		FStringAssetReference AssetToLoad = LoadMeshesDataBase->MeshList[Id].StaticMeshResource.ToStringReference();
		HandleAssetToLoadMap.Add(Id, AssetToLoad);
		ObjToLoad.AddUnique(AssetToLoad);
		BaseLoader.RequestAsyncLoad(ObjToLoad, FStreamableDelegate::CreateUObject(this, &ASceneAssetManager::DoAsyncAssetLoad));
		return true;
	}
	return false;
}

bool ASceneAssetManager::LoadSceneAssetToActor(int32 Id, AStaticMeshAssetActor* AssetActor)
{
	FStreamableManager& BaseLoader = UGameSingleton::Get().AssetLoader;
	FStringAssetReference AssetToLoad = LoadMeshesDataBase->MeshList[Id].StaticMeshResource.ToStringReference();
	UObject* AssetObject = BaseLoader.SynchronousLoad(AssetToLoad);
	AssetActor->LoadStaticMeshAsset(AssetObject);
	return true;
}

bool ASceneAssetManager::LoadAssetPackage()
{
	//timeload = 0;
	//for (FItemDataInfo AssetPtr : LoadMeshesDataBase->MeshList)
	//{
	//	UStaticMesh* StaticObj = AssetPtr.StaticMeshResource.Get();
	//}

	if (LoadMeshesDataBase != NULL && LoadMeshesDataBase->MeshList.Num() > 0)
	{
		TArray<FStringAssetReference> ObjToLoad;
		FStreamableManager& BaseLoader = UGameSingleton::Get().AssetLoader;
		for (FAssetDataInfo AssetPtr : LoadMeshesDataBase->MeshList)
		{
			ObjToLoad.AddUnique(AssetPtr.StaticMeshResource.ToStringReference());
		}
		BaseLoader.RequestAsyncLoad(ObjToLoad, FStreamableDelegate::CreateUObject(this, &ASceneAssetManager::DoAsyncAssetChange));
		return true;
	}
	return false;
}

void ASceneAssetManager::DoAsyncAssetChange()
{
	for (FAssetDataInfo AssetPtr : LoadMeshesDataBase->MeshList)
	{
		UStaticMesh* StaticObj = AssetPtr.StaticMeshResource.Get();
		InstanceAssetToLevel(StaticObj, AssetPtr.MeshID);
		spawnindex += 1;
	}
	if (spawnindex >= 5000)
	{
		return;
	}
	LoadAssetPackage();
}


bool ASceneAssetManager::ChangeSceneAsset(int32 OldAssetId, int32 NewAssetId)
{
	//AStaticMeshAssetActor* AssetActor = nullptr;
	//TArray<int32> KeyArray;
	//InstanceAssetMap.GenerateKeyArray(KeyArray);
	//if (KeyArray.Contains(NewAssetId))
	//{
	//	TArray<AStaticMeshAssetActor*> AssetActorArray = InstanceAssetMap[NewAssetId];
	//	for (auto AssetIter(AssetActorArray.CreateConstIterator()); AssetIter; AssetIter++)
	//	{
	//		AssetActor = *AssetIter;
	//	}
	//}
	//if (LoadMeshesDataBase != NULL && LoadMeshesDataBase->MeshList.Contains(NewAssetId))
	//{
	//	TArray<FStringAssetReference> ObjToLoad;
	//	FStreamableManager& BaseLoader = UGameSingleton::Get().AssetLoader;
	//	FStringAssetReference AssetToLoad = LoadMeshesDataBase->MeshList[NewAssetId].StaticMeshResource.ToStringReference();
	//	HandleAssetToLoadMap.Add(NewAssetId, AssetToLoad);
	//	ObjToLoad.AddUnique(AssetToLoad);
	//	BaseLoader.RequestAsyncLoad(ObjToLoad, FStreamableDelegate::CreateUObject(this, &ASceneAssetManager::DoAsyncAssetChange));
	//	return true;
	//}
	FStringAssetReference AssetToLoad = LoadMeshesDataBase->MeshList[NewAssetId].StaticMeshResource.ToStringReference();
	FStreamableManager& BaseLoader = UGameSingleton::Get().AssetLoader;
	BaseLoader.SimpleAsyncLoad(AssetToLoad);

	UObject* NewAsset = AssetToLoad.ResolveObject();
	if (NewAsset != nullptr)
	{
		TArray<AStaticMeshAssetActor*> ActorArray = InstanceAssetMap[OldAssetId];
		for (AStaticMeshAssetActor* obj : ActorArray)
		{
			obj->LoadStaticMeshAsset(NewAsset);
		}
		return true;
	}
	return false;
}

void ASceneAssetManager::UnloadSceneAsset(int32 Id)
{
	FStreamableManager& BaseLoader = UGameSingleton::Get().AssetLoader;
	FStringAssetReference AssetToLoad = LoadMeshesDataBase->MeshList[Id].StaticMeshResource.ToStringReference();
	
	//释放指定资源文件
	BaseLoader.Unload(AssetToLoad);
	//直接释放流管理器
	BaseLoader.~FStreamableManager();
}

void ASceneAssetManager::DoAsyncAssetLoad()
{
	check(HandleAssetToLoadMap[Index].ResolveObject() != nullptr)
	{
		UObject* NewAsset = HandleAssetToLoadMap[Index].ResolveObject();
		InstanceAssetToLevel(NewAsset, Index);
		HandleAssetToLoadMap.Remove(Index);
	}
	if (Index+1 >= AllAssetNum)
	{
		allspawnnum += AllAssetNum;
		if (allspawnnum >= 10000)
		{
			return;
		}
		Index = 0;
	}
//	LoadSceneAsset(Index + 1);
}

void ASceneAssetManager::InstanceAssetToLevel(UObject* AssetObject, int32 Id)
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
//	FVector loc = UKismetMathLibrary::RandomPointInBoundingBox(FVector::ZeroVector, FVector(530, -30, 240)); //(X=530.000000,Y=-30.000000,Z=240.000000)
	FVector loc = FVector(530, -30, 240);
	FTransform FTPoint(FRotator::ZeroRotator, loc);
	AStaticMeshAssetActor* test = GetWorld()->SpawnActor<AStaticMeshAssetActor>(AStaticMeshAssetActor::StaticClass(), FTPoint, SpawnInfo);

	TArray<int32> KeyArray;
	InstanceAssetMap.GenerateKeyArray(KeyArray);
	if (KeyArray.Num() <= 0)
	{
		TArray<AStaticMeshAssetActor*> ActorArray;
		ActorArray.Add(test);
		InstanceAssetMap.Add(Id, ActorArray);
	}
	else
	{
		if (KeyArray.Contains(Id))
		{
			InstanceAssetMap[Id].Add(test);
		}
		else
		{
			TArray<AStaticMeshAssetActor*> ActorArray;
			ActorArray.Add(test);
			InstanceAssetMap.Add(Id, ActorArray);
		}
	}
	test->LoadStaticMeshAsset(AssetObject, 0);
}

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif
