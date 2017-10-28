// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "BatchLODToolStyle.h"

class FBatchLODToolCommands : public TCommands<FBatchLODToolCommands>
{
public:

	FBatchLODToolCommands()
		: TCommands<FBatchLODToolCommands>(TEXT("BatchLODTool"), NSLOCTEXT("Contexts", "BatchLODTool", "BatchLODTool Plugin"), NAME_None, FBatchLODToolStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
