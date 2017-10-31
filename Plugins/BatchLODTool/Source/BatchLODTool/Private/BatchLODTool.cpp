// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BatchLODTool.h"
#include "BatchLODToolStyle.h"
#include "BatchLODToolCommands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#include "BatchLODSetting.h"
#include "ISettingsModule.h"
#include "Editor/ContentBrowser/Public/ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "AssetToolsModule.h"

#include "LevelEditor.h"
#include "ISettingsContainer.h"
#include "ISettingsSection.h"

static const FName BatchLODToolTabName("BatchLODTool");

#define LOCTEXT_NAMESPACE "FBatchLODToolModule"

void FBatchLODToolModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FBatchLODToolStyle::Initialize();
	FBatchLODToolStyle::ReloadTextures();

	FBatchLODToolCommands::Register();
	
	RegisterSettings();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FBatchLODToolCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FBatchLODToolModule::PluginButtonClicked),
		FCanExecuteAction());
	InstallCBHook();
}

void FBatchLODToolModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UnRegisterSettings();
	}
	FBatchLODToolStyle::Shutdown();
	FBatchLODToolCommands::Unregister();
}

void FBatchLODToolModule::InstallCBHook()
{
	FContentBrowserModule& AssetContextModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	//处理资源
	FContentBrowserMenuExtender_SelectedAssets CBExtenderDelegate;
	CBExtenderDelegate = FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FBatchLODToolModule::OnExtendCBAssetSelectionMenu);
	AssetContextModule.GetAllAssetViewContextMenuExtenders().Add(CBExtenderDelegate);
}

void FBatchLODToolModule::RegisterSettings()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

	SettingsContainer->DescribeCategory("LODSettings", 
		LOCTEXT("LODCategoryName", "LODSettings"),
		LOCTEXT("LODCategoryDescription", "auto setting the lod percent"));

	ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "LODSettings", "General",
		LOCTEXT("LODGeneralSettingsName", "General"),
		LOCTEXT("LODGeneralSettingsDescription", "Base configuration for LOD Setting"),
		GetMutableDefault<UBatchLODSetting>()
	);
	if (SettingsSection.IsValid())
	{
		SettingsSection->OnModified().BindRaw(this, &FBatchLODToolModule::HandleLODSettingSaved);
	}
}

void FBatchLODToolModule::UnRegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "LODSettings", "General");
	}
}

bool FBatchLODToolModule::SupportsDynamicReloading()
{
	return true;
}

TSharedRef<FExtender> FBatchLODToolModule::OnExtendCBAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender(new FExtender());
	Extender->AddMenuExtension(
		"GetAssetActions",
		EExtensionHook::After,
		PluginCommands,
		FMenuExtensionDelegate::CreateRaw(this, &FBatchLODToolModule::AddAnalysisExtension)
	);
	return Extender;
}

void FBatchLODToolModule::AddAnalysisExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FBatchLODToolCommands::Get().PluginAction);
}

void FBatchLODToolModule::PluginButtonClicked()
{
	FContentBrowserModule& AssetContextModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	AssetContextModule.Get().GetSelectedAssets(AssetData);
	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");

	FAssetData assetdata =FAssetData::GetFirstAssetDataOfClass(AssetData, UStaticMesh::StaticClass());

	TArray<UStaticMesh*> TempArray;
	for (int32 i = 0; i < AssetData.Num(); i++)
	{
		TempArray.Add(Cast<UStaticMesh>(AssetData[i].ToStringReference().TryLoad()));
	}
	ApplyChangeLODSetting(TempArray);
}

void FBatchLODToolModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FBatchLODToolCommands::Get().PluginAction);
}   

bool FBatchLODToolModule::HandleLODSettingSaved()
{
	UBatchLODSetting* Settings = GetMutableDefault<UBatchLODSetting>();
	bool ResaveSettings = false;

	//这里可以加过滤条件
	Settings->SaveConfig();
	return true;
}

void FBatchLODToolModule::ApplyChangeLODSetting(TArray<UStaticMesh*> MeshArray)
{
	UBatchLODSetting* Settings = GetMutableDefault<UBatchLODSetting>();

	bool NoChange = true;

	int32 LODCount = Settings->ReductionSettings.Num();

	UStaticMesh* StaticMesh = nullptr;
	for (int32 i = 0; i < MeshArray.Num(); i++)
	{
		StaticMesh = MeshArray[i];
		StaticMesh->Modify();

		if (StaticMesh->SourceModels.Num() > LODCount)
		{
			int32 NumToRemove = StaticMesh->SourceModels.Num() - LODCount;
			StaticMesh->SourceModels.RemoveAt(LODCount, NumToRemove);
		}

		while (StaticMesh->SourceModels.Num() < LODCount)
		{
			new(StaticMesh->SourceModels) FStaticMeshSourceModel();
		}
		check(StaticMesh->SourceModels.Num() == LODCount);

		for (int32 LODIndex = 0; LODIndex < LODCount; ++LODIndex)
		{
			FStaticMeshSourceModel& SrcModel = StaticMesh->SourceModels[LODIndex];
			SrcModel.ReductionSettings.PercentTriangles = Settings->ReductionSettings[LODIndex].PercentTriangles;
			SrcModel.ReductionSettings.TextureImportance = Settings->ReductionSettings[LODIndex].TextureImportance;
			SrcModel.ReductionSettings.ShadingImportance = Settings->ReductionSettings[LODIndex].ShadingImportance;
			//StaticMeshEditorTools.cpp 3320
		}
		StaticMesh->PostEditChange();
	}
}

void FBatchLODToolModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FBatchLODToolCommands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBatchLODToolModule, BatchLODTool)