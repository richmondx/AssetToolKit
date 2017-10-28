// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "AssetToolKitPanelPrivatePCH.h"
#include "AssetToolKitPanelStyle.h"
#include "SlateGameResources.h"
#include "IPluginManager.h"

TSharedPtr< FSlateStyleSet > FAssetToolKitPanelStyle::StyleInstance = NULL;

void FAssetToolKitPanelStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FAssetToolKitPanelStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FAssetToolKitPanelStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("AssetToolKitPanelStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FAssetToolKitPanelStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("AssetToolKitPanelStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("AssetToolKit")->GetBaseDir() / TEXT("Resources"));

	const FTextBlockStyle TabButtonText = FTextBlockStyle()
		.SetFont(TTF_FONT("Fonts/Roboto-Bold", 10)) //设置字体
		.SetColorAndOpacity(FSlateColor::UseForeground())//设置颜色和透明度
		.SetShadowColorAndOpacity(FLinearColor::Black) //设置阴影颜色和透明度
		.SetHighlightColor(FLinearColor(0.02f, 0.3f, 0.0f)) //设置高光颜色
		.SetShadowOffset(FVector2D(-1, 1)) //设置阴影偏移
		.SetHighlightShape(BOX_BRUSH("Common/TextBlockHighlightShape", FMargin(3.f / 8.f))); //设置高光形状

	Style->Set("TabButton.Text", TabButtonText);

	const FButtonStyle NoBorder = FButtonStyle()
		.SetNormal(FSlateNoResource())
		.SetHovered(FSlateNoResource())
		.SetPressed(FSlateNoResource())
		.SetNormalPadding(FMargin(0, 0, 0, 1))
		.SetPressedPadding(FMargin(0, 1, 0, 0));

	Style->Set("NoBorderButton", NoBorder);
	Style->Set("NoBorder", new FSlateNoResource());

	Style->Set("AssetToolKitPanel.OpenPluginWindow", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));

	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FAssetToolKitPanelStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FAssetToolKitPanelStyle::Get()
{
	return *StyleInstance;
}
