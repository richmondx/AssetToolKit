#pragma once
#include "Runtime/Engine/Classes/Engine/StreamableManager.h"
class IPlatformFile;
class FPakPlatformFile;
struct FStringAssetReference;
//struct FStreamableManager;

class ASSETTOOLKITRUNTIME_API IAssetStreamerListener
{
public:
	virtual void OnAssetStreamComplete() = 0;

	virtual void OnPrepareAssetStreaming(const TArray<FStringAssetReference>& StreamedAssets) = 0;
};

class ASSETTOOLKITRUNTIME_API FAssetStreamerListener : public IAssetStreamerListener
{
public:
	virtual void OnAssetStreamComplete() override
	{

	}

	virtual void OnPrepareAssetStreaming(const TArray<FStringAssetReference>& StreamedAssets) override
	{
		TArray<FStringAssetReference> tt = StreamedAssets;
	}
};

class ASSETTOOLKITRUNTIME_API FAssetPakExecuteStreamer
{
public:
	FAssetPakExecuteStreamer();
	~FAssetPakExecuteStreamer();

	bool Initialize(FStreamableManager* mStreamableManager);

	bool StreamPackage(const FString& PakFileName, IAssetStreamerListener* AssetStreamerListener, const TCHAR* CmdLine);

	uint32 bInitialized : 1;

	bool IsStreaming() const
	{
		return LockValue != 0;
	}

	void BlockUntilStreamingFinished(float SleepTime = 0.1f) const
	{
		while (LockValue != 0)
		{
			FPlatformProcess::Sleep(SleepTime);
		}
	}

private:
	FString GetResolveLocalPath(const FString& FileName);

	void Lock()
	{
		FPlatformAtomics::InterlockedExchange(&LockValue, 1);
	}

	void Unlock()
	{
		FPlatformAtomics::InterlockedExchange(&LockValue, 0);
	}

	void OnStreamingCompleteDelegate();

	volatile int32 LockValue;

	IPlatformFile* LocalPlatformFile;
	TSharedPtr<FPakPlatformFile> PakPlatform;

	IAssetStreamerListener* Listener;
	TArray<FStringAssetReference> StreamedAssets;
	bool bSigned;

	FStreamableManager* StreamableManager;
};