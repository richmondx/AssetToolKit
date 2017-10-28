// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "AssetToolKitPrivatePCH.h"
#include "AssetToolKitCommands.h"

#define LOCTEXT_NAMESPACE "FAssetToolKitModule"

void FAssetToolKitCommands::RegisterCommands()
{
	UI_COMMAND(PluginPak, "AssetPak", "Execute AssetToolKit Pak AssetDate", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(PluginAction, "AssetData", "Execute AssetToolKit Create AssetDate", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
