// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AssetDataBase.h"
#include "StaticMeshAssetActor.h"
#include "SceneAssetManager.generated.h"

USTRUCT()
struct FSceneAssetInfo
{
	GENERATED_USTRUCT_BODY()

public:

	FSceneAssetInfo()
	{
	}
};

//DECLARE_DELEGATE_TwoParams(FCustomStreamableDelegate, int32 OldIndex, int32 NewIndex)

UCLASS()
class ASSETTOOLKITRUNTIME_API ASceneAssetManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASceneAssetManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void PostInitializeComponents() override;

	//指定加载对象
	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
	bool LoadSceneAsset(int32 Id);

	//指定加载资源到对应的实例
	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
	bool LoadSceneAssetToActor(int32 Id, AStaticMeshAssetActor* AssetActor);

	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
	bool LoadAssetPackage();

	//指定更改对象
	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
	bool ChangeSceneAsset(int32 OldAssetId, int32 NewAssetId);

	//指定卸载对象
	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
	void UnloadSceneAsset(int32 Id);

	//异步加载对象
	void DoAsyncAssetLoad();

	//异步更新对象
	UFUNCTION(BlueprintCallable, Category = "AssetLoad")
	void DoAsyncAssetChange();

	//实例资源到场景
	void InstanceAssetToLevel(UObject* AssetObject, int32 Id);

private:

	UAssetDataBase* LoadMeshesDataBase = nullptr;

	FString AssetDataPath = "/Game/MeshList.MeshList";

	TMap<int32, FStringAssetReference> HandleAssetToLoadMap;

	int32 Index = 0;

	int32 AllAssetNum = 0;

	int32 allspawnnum = 0;

	TMap<int32, TArray<AStaticMeshAssetActor*>> InstanceAssetMap;

	TArray<AStaticMeshAssetActor*> AssetActorStream;

	int32 spawnindex = 0;

	float timeload = 0;
};
