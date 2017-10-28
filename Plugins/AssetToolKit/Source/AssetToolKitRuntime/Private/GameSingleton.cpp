// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetToolKitRuntimePrivatePCH.h"
#include "GameSingleton.h"

UGameSingleton::UGameSingleton(const class FObjectInitializer& Obj) : Super(Obj)
{

}

UGameSingleton& UGameSingleton::Get()
{
	UGameSingleton* Singleton = Cast<UGameSingleton>(GEngine->GameSingleton);
	if (Singleton)
	{
		return *Singleton;
	}
	else
	{
		return *NewObject<UGameSingleton>(UGameSingleton::StaticClass());
	}
}

bool UGameSingleton::Tick(float DeltaTime)
{
	return true;
}
