// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "SceneAssetManager.h"
#include "AssetExecutePakFile.generated.h"

/**
 * 
 */
UCLASS()
class ASSETTOOLKITRUNTIME_API UAssetExecutePakFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Pak")
	static void ExecutePakFile();

	UFUNCTION(BlueprintCallable, Category = "Pak")
	static void SetSceneManage(ASceneAssetManager* Man);

	static ASceneAssetManager* GetSceneAssetMan() { return m_Man;  }

private:

	static ASceneAssetManager* m_Man;
};
