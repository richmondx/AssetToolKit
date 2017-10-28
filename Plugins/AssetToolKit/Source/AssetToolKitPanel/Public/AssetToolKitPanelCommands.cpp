// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "AssetToolKitPanelPrivatePCH.h"
#include "AssetToolKitPanelCommands.h"

#define LOCTEXT_NAMESPACE "FAssetToolKitPanelModule"

void FAssetToolKitPanelCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "AssetToolKitPanel", "Bring up AssetToolKitPanel window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
