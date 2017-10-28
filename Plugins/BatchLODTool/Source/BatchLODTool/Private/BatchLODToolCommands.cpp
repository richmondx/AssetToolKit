// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BatchLODToolCommands.h"

#define LOCTEXT_NAMESPACE "FBatchLODToolModule"

void FBatchLODToolCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "BatchLODTool", "Execute BatchLODTool Auto Set Asset's LOD", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
