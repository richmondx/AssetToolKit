// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "AssetToolKitPanelPrivatePCH.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

#include "AssetToolKitPanelStyle.h"
#include "AssetToolKitPanelCommands.h"

#include "LevelEditor.h"

static const FName AssetToolKitPanelTabName("AssetToolKitPanel");

#define LOCTEXT_NAMESPACE "FAssetToolKitPanelModule"

void FAssetToolKitPanelModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FAssetToolKitPanelStyle::Initialize();
	FAssetToolKitPanelStyle::ReloadTextures();

	FAssetToolKitPanelCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FAssetToolKitPanelCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FAssetToolKitPanelModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		//TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		//MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FAssetToolKitPanelModule::AddMenuExtension));

		//LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FAssetToolKitPanelModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(AssetToolKitPanelTabName, FOnSpawnTab::CreateRaw(this, &FAssetToolKitPanelModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FAssetToolKitPanelTabTitle", "AssetToolKitPanel"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FAssetToolKitPanelModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FAssetToolKitPanelStyle::Shutdown();

	FAssetToolKitPanelCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(AssetToolKitPanelTabName);
}

TSharedRef<SDockTab> FAssetToolKitPanelModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FAssetToolKitPanelModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("AssetToolKitPanel.cpp"))
	);

	TSharedRef<SDockTab> ResultTab = SNew(SDockTab).TabRole(ETabRole::NomadTab);
//	TSharedRef<SWidget> TabContentWidget = SNew()

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FAssetToolKitPanelModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(AssetToolKitPanelTabName);
}

void FAssetToolKitPanelModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FAssetToolKitPanelCommands::Get().OpenPluginWindow);
}

void FAssetToolKitPanelModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FAssetToolKitPanelCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAssetToolKitPanelModule, AssetToolKitPanel)