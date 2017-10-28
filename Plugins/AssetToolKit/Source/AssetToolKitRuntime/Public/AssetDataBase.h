// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "Engine/SkeletalMesh.h"
#include "AssetDataBase.generated.h"

/**
 * 资源
 */

USTRUCT()
struct FAssetDataInfo
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "DATA", meta = (ToolTip = "The Mesh ID"))
		int32 MeshID;

	//UPROPERTY(EditAnywhere, Category = "DATA", meta = (ToolTip = "Related Asset"))
	//	TAssetPtr<USkeletalMesh> SkeletalMeshResource;

	UPROPERTY(EditAnywhere, Category = "DATA", meta = (ToolTip = "Related Asset"))
	TAssetPtr<UStaticMesh> StaticMeshResource;

	FAssetDataInfo()
	{
		MeshID = 0;
//		SkeletalMeshResource = FStringAssetReference("");
		StaticMeshResource = FStringAssetReference("");
	}
};

UCLASS()
class ASSETTOOLKITRUNTIME_API UAssetDataBase : public UDataAsset
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Model List", meta = (ToolTip = "Asset Info"))
		TArray<FAssetDataInfo> MeshList;

	UAssetDataBase() {};
};
