#include "AssetToolKitPanelPrivatePCH.h"
#include "FileButton.h"

#include "AssetToolKitPanelStyle.h"

void SFileButton::Construct(const FArguments& InArgs)
{
	IsActive = InArgs._OnIsActive;
	OnButtonClicked = InArgs._OnButtonClicked;

	TSharedRef<SWidget> ButtonWidget = SNew(SButton)
		.ForegroundColor(FCoreStyle::Get().GetSlateColor("Foreground"))
		.Text(InArgs._ButtonLabel)
		.TextStyle(FAssetToolKitPanelStyle::Get(), TEXT("TabButton.Text"))
		.ContentPadding(FMargin(15, 5))
		.OnClicked(OnButtonClicked);

	this->ChildSlot
		[
			SNew(SBorder)
			.Padding(0.0f)
			.BorderImage(FAssetToolKitPanelStyle::Get().GetBrush(TEXT("NoBorder")))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight()
				[
					ButtonWidget
				]
			]
		];
}