// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SlateBasics.h"
#include "AssetToolKitStyle.h"

class FAssetToolKitCommands : public TCommands<FAssetToolKitCommands>
{
public:

	FAssetToolKitCommands()
		: TCommands<FAssetToolKitCommands>(TEXT("AssetToolKit"), NSLOCTEXT("Contexts", "AssetToolKit", "AssetToolKit Plugin"), NAME_None, FAssetToolKitStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
	TSharedPtr< FUICommandInfo > PluginPak;
};
