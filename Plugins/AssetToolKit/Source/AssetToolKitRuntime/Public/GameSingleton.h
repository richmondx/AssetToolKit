// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Containers/Ticker.h"
#include "Engine/StreamableManager.h"
#include "GameSingleton.generated.h"

/**
 * 
 */

UCLASS(Config =Game, notplaceable)
class ASSETTOOLKITRUNTIME_API UGameSingleton : public UObject, public FTickerObjectBase
{
	GENERATED_UCLASS_BODY()
	
private:
	UGameSingleton();
public:
	static UGameSingleton& Get();
	FStreamableManager AssetLoader;

	virtual bool Tick(float DeltaTime) override;
};
