// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetToolKitPanelPrivatePCH.h"
#include "AssetToolContentPanel.h"
#include "AssetToolKitPanelStyle.h"

#include "UnrealEd.h"
#include "Editor/UnrealEd/Classes/Editor/EditorEngine.h"
#include "Runtime/Engine/Classes/Engine/BrushBuilder.h"
#include "Editor/UnrealEd/Classes/Builders/CubeBuilder.h"

#include "SlateExtras.h"

extern UNREALED_API class UEditorEngine* GEditor;

#define LOCTTEXT_NAMESPACE "AssetToolKitPanelPlugin"

SAssetToolContentPanel::SAssetToolContentPanel()
{
	//const FText PanelTitleName = LOCTEXT("PanelTitle", "资源列表");
	//const FText LoadSelectedBtnName = LOCTEXT("LoadSelectedBtn", "载入资源");
	//const FText HandleDataAssetBtnName = LOCTEXT("HandleDataAssetBtn", "生成数据表");
	//const FText PakDataAssetBtnName = LOCTEXT("PakDataAssetBtn", "压缩成Pak包");
	//const FText PluginUseDescription = LOCTEXT("PluginUseDesc", "资源处理插件使用说明！");
}

SAssetToolContentPanel::~SAssetToolContentPanel()
{

}

void SAssetToolContentPanel::Construct(const FArguments& InArgs, TSharedPtr<SDockTab> InOwnerTab)
{
	OwnerTab = InOwnerTab;
	OnPluginCreated = InArgs._OnPluginCreated;


}

#undef LOCTEXT_NAMESPACE