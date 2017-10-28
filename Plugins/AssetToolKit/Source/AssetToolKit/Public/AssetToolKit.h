// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "AssetToolFactory.h"
#include "AssetDatabase.h"
#include "AssetData.h"

class FToolBarBuilder;
class FMenuBuilder;

class FAssetToolKitModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	void InstallCBHook();

	TSharedRef<FExtender> OnExtendCBAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets);

	TSharedRef<FExtender> OnExtendCBAssetSelectionMenuPak(const TArray<FAssetData>& SelectedAssets);

	void AddAnalysisExtension(FMenuBuilder& Builder);

	void AddAnalysisExtensionPak(FMenuBuilder& Builder);

	/** This function will be bound to Command. */
	void PluginButtonClicked();

	void PluginPakClicked();

	void HandleAssetData(UAssetDataBase* Data);

	void ExecuteCmdPak();
	
	UAssetToolFactory* AssetFactorySingleton;

	TArray<FAssetData> AssetData;

private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

private:
	TSharedPtr<class FUICommandList> PluginCommands;
	FString PakCmd = "";
};