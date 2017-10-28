// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SlateBasics.h"
#include "AssetToolKitPanelStyle.h"

class FAssetToolKitPanelCommands : public TCommands<FAssetToolKitPanelCommands>
{
public:

	FAssetToolKitPanelCommands()
		: TCommands<FAssetToolKitPanelCommands>(TEXT("AssetToolKitPanel"), NSLOCTEXT("Contexts", "AssetToolKitPanel", "AssetToolKitPanel Plugin"), NAME_None, FAssetToolKitPanelStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};