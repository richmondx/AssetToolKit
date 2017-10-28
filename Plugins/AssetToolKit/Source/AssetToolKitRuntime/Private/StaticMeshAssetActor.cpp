// Fill out your copyright notice in the Description page of Project Settings.
#include "AssetToolKitRuntimePrivatePCH.h"
#include "StaticMeshAssetActor.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif


AStaticMeshAssetActor::AStaticMeshAssetActor(const class FObjectInitializer& OBJ) : Super(OBJ)
{

}

void AStaticMeshAssetActor::LoadStaticMeshAsset(UObject* Obj, int32 MeshId)
{
	UStaticMesh* st = Cast<UStaticMesh>(Obj);
	GetStaticMeshComponent()->SetStaticMesh(st);
//	GetStaticMeshComponent()->SetCastShadow(false);
//	GetRootComponent()->SetMobility(EComponentMobility::Static);
	UseMeshAssetId = MeshId;
}

void AStaticMeshAssetActor::LoadStaticMeshAsset(UObject* Obj)
{
	LoadStaticMeshAsset(Obj, UseMeshAssetId);
}

void AStaticMeshAssetActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GetRootComponent()->SetMobility(EComponentMobility::Movable);
}

#if PLATFORM_WINDOWS 
#pragma optimize("",on) 
#endif