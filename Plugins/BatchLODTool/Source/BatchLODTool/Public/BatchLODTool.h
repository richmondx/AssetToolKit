// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"
#include "ISettingsViewer.h"
#include "AssetData.h"

class FToolBarBuilder;
class FMenuBuilder;
class UBatchLODFactory;

static const FName LODSettingsTabName("LODSettings");


class FBatchLODToolModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	void InstallCBHook();

	void RegisterSettings();
	void UnRegisterSettings();

	virtual bool SupportsDynamicReloading() override;

	TSharedRef<FExtender> OnExtendCBAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets);
	void AddAnalysisExtension(FMenuBuilder& Builder);

	/** This function will be bound to Command. */
	void PluginButtonClicked();

	TArray<FAssetData> GetSelectedAssetDatas()
	{
		return AssetData;
	}

private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

	bool HandleLODSettingSaved();

	void ApplyChangeLODSetting(TArray<UStaticMesh*> MeshArray);

private:
	TSharedPtr<class FUICommandList> PluginCommands;

	//被选中的资源列表
	TArray<FAssetData> AssetData;
	UBatchLODFactory* AssetFactorySingleton;
};