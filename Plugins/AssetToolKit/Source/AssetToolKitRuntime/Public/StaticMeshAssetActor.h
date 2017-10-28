// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "StaticMeshAssetActor.generated.h"

/**
 * 
 */
UCLASS()
class ASSETTOOLKITRUNTIME_API AStaticMeshAssetActor : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()
	
public:

	void LoadStaticMeshAsset(UObject* Obj, int32 MeshId);

	void LoadStaticMeshAsset(UObject* Obj);

	virtual void PostInitializeComponents() override;

	int32 GetMeshAssetId() { return UseMeshAssetId; }
	
private:
	
	int32 UseMeshAssetId = 0;
	
};
