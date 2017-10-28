// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetToolKitPrivatePCH.h"
#include "AssetDataBase.h"
#include "AssetToolFactory.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

#define LOCTEXT_NAMESPACE "AssetTool"

UAssetToolFactory::UAssetToolFactory(const class FObjectInitializer& Obj) : Super(Obj)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UAssetDataBase::StaticClass();
}

UObject* UAssetToolFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	FAssetToolKitModule& AssetContextModule = FModuleManager::LoadModuleChecked<FAssetToolKitModule>("AssetToolKit");

	TArray<FAssetData> assets = AssetContextModule.AssetData;

	UAssetDataBase* NewAsset = NewObject<UAssetDataBase>(InParent, InClass, InName, Flags | RF_Transactional);

	for (int32 i = 0; i < assets.Num(); i++)
	{
		FAssetDataInfo fstructdata;
		TAssetPtr<UStaticMesh> tt;
		tt = TAssetPtr<UStaticMesh>(assets[i].GetAsset());
		fstructdata.StaticMeshResource = tt;
		fstructdata.MeshID = i;
		NewAsset->MeshList.Add(fstructdata);
	}
	return NewAsset;
}

#define LOCTEXT_NAMESPACE "AssetTool"

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif