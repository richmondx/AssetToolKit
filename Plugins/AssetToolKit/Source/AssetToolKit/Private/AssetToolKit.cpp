// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "AssetToolKitPrivatePCH.h"

#include <windows.h>
#include <stdio.h>

#include "SlateBasics.h"
#include "SlateExtras.h"

#include "AssetToolKitStyle.h"
#include "AssetToolKitCommands.h"

#include "Editor/ContentBrowser/Public/ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "AssetToolsModule.h"

#include "LevelEditor.h"

using namespace std;

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

static const FName AssetToolKitTabName("AssetToolKit");

#define LOCTEXT_NAMESPACE "FAssetToolKitModule"

void FAssetToolKitModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FAssetToolKitStyle::Initialize();
	FAssetToolKitStyle::ReloadTextures();

	FAssetToolKitCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FAssetToolKitCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FAssetToolKitModule::PluginButtonClicked),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FAssetToolKitCommands::Get().PluginPak,
		FExecuteAction::CreateRaw(this, &FAssetToolKitModule::PluginPakClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

	{
		PakCmd = "UnrealPak.exe " + FAssetToolKitStyle::GetResourcePath() / TEXT("test.pak") + " -create=" + FAssetToolKitStyle::GetResourcePath() / TEXT("paklist.txt") + " -order=" + FAssetToolKitStyle::GetResourcePath() / TEXT("cookopen.log") + " -UTF8Output" + " -encrypt" + " -compress";
		InstallCBHook();
	}

	//去掉默认界面上的按钮
	{
		//TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		//MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FAssetToolKitModule::AddMenuExtension));

		//LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		//TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		//ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FAssetToolKitModule::AddToolbarExtension));
		//
		//LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FAssetToolKitModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FAssetToolKitStyle::Shutdown();

	FAssetToolKitCommands::Unregister();
}

void FAssetToolKitModule::InstallCBHook()
{

	FContentBrowserModule& AssetContextModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	//处理资源
	FContentBrowserMenuExtender_SelectedAssets CBExtenderDelegate;
	CBExtenderDelegate = FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FAssetToolKitModule::OnExtendCBAssetSelectionMenu);
	AssetContextModule.GetAllAssetViewContextMenuExtenders().Add(CBExtenderDelegate);

	//打包数据表（根据数据表中记录的数据，依次获取到资源的路径，记录成paklist.txt，然后去生成Pak文件）
	FContentBrowserMenuExtender_SelectedAssets CBExtenderDelegatePak;
	CBExtenderDelegatePak = FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FAssetToolKitModule::OnExtendCBAssetSelectionMenuPak);
	AssetContextModule.GetAllAssetViewContextMenuExtenders().Add(CBExtenderDelegatePak);

//	fcontenbrowser
}

TSharedRef<FExtender> FAssetToolKitModule::OnExtendCBAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender(new FExtender());
	Extender->AddMenuExtension(
		"GetAssetActions",
		EExtensionHook::After,
		PluginCommands,
		FMenuExtensionDelegate::CreateRaw(this, &FAssetToolKitModule::AddAnalysisExtension)
	);
		return Extender;
}

TSharedRef<FExtender> FAssetToolKitModule::OnExtendCBAssetSelectionMenuPak(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender(new FExtender());

	if (SelectedAssets.Num() == 1 && SelectedAssets[0].AssetClass == "AssetDataBase")
	{
		Extender->AddMenuExtension(
			"CommonAssetActions",
			EExtensionHook::After,
			PluginCommands,
			FMenuExtensionDelegate::CreateRaw(this, &FAssetToolKitModule::AddAnalysisExtensionPak)
		);
	}
	return Extender;
}

void FAssetToolKitModule::AddAnalysisExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FAssetToolKitCommands::Get().PluginAction);
}

void FAssetToolKitModule::AddAnalysisExtensionPak(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FAssetToolKitCommands::Get().PluginPak);
}

void FAssetToolKitModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	//FText DialogText = FText::Format(
	//						LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
	//						FText::FromString(TEXT("FAssetToolKitModule::PluginButtonClicked()")),
	//						FText::FromString(TEXT("AssetToolKit.cpp"))
	//				   );
	//FMessageDialog::Open(EAppMsgType::Ok, DialogText);

	FContentBrowserModule& AssetContextModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	AssetContextModule.Get().GetSelectedAssets(AssetData);

	AssetFactorySingleton = NewObject<UAssetToolFactory>();

	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");

	AssetToolsModule.Get().CreateAsset(UAssetDataBase::StaticClass(), AssetFactorySingleton, NAME_None);

	//AssetFactorySingleton->FactoryCreateNew(UAssetDataBase::StaticClass(), Pkg, TEXT("NewAssetData"), EObjectFlags::RF_Standalone, nullptr, nullptr);

//	AssetContextModule.Get().CreateNewAsset(assetName, "/Game/Assets/", UAssetDataBase::StaticClass(), AssetFactorySingleton);
	
}

void FAssetToolKitModule::PluginPakClicked()
{
	FContentBrowserModule& AssetContextModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetData> AssetData2;
	AssetContextModule.Get().GetSelectedAssets(AssetData2);

	if (AssetData2.Num() == 1)
	{
		FAssetData tempData = AssetData2[0];
		UAssetDataBase*  Data = Cast<UAssetDataBase>(tempData.ToStringReference().ResolveObject());
		HandleAssetData(Data);
	}
}

void FAssetToolKitModule::HandleAssetData(UAssetDataBase* Data)
{
	std::string tts(TCHAR_TO_UTF8(*PakCmd));

	TAssetPtr<UStaticMesh> tta;
	FString alltxt = "";

	for (FAssetDataInfo asset : Data->MeshList)
	{
		 tta = asset.StaticMeshResource;
		 FString LocalPath1 = FPaths::GameContentDir(); 
		 FString gamecontent = tta.GetLongPackageName();
		 gamecontent = UKismetStringLibrary::GetSubstring(gamecontent, 6, gamecontent.Len() - 1).Append(".uasset"); //将/Game/路径转成/Content/路径 （盘符路径）
		 LocalPath1 = LocalPath1 + gamecontent;
		 alltxt = alltxt + LocalPath1 + "\r\n";
	}

	FString paklistPath = FAssetToolKitStyle::GetResourcePath() / TEXT("paklist.txt");
	FFileHelper::SaveStringToFile(alltxt, *paklistPath, FFileHelper::EEncodingOptions::Type::ForceUTF8);

	//执行cmd命令
	system(tts.c_str());

	FString pakfilePath = FAssetToolKitStyle::GetResourcePath() / TEXT("test.pak");

	auto Message = NSLOCTEXT("UnrealClient", "Pak AssetData Successful.", "Pak AssetData Successful.");

	//检查Pak文件是否正常生成
	if (!IFileManager::Get().FileExists(*pakfilePath))
	{
		Message = NSLOCTEXT("UnrealClient", "Pak AssetData Failed.", "Pak AssetData Failed.");
	}

	FNotificationInfo Info(Message);
	Info.bFireAndForget = true;
	Info.ExpireDuration = 5.0f;
	Info.bUseSuccessFailIcons = false;
	Info.bUseLargeFont = false;

	FSlateNotificationManager::Get().AddNotification(Info);
}

void FAssetToolKitModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FAssetToolKitCommands::Get().PluginAction);
}

void FAssetToolKitModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FAssetToolKitCommands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAssetToolKitModule, AssetToolKit)


#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif
