// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/AssetToolKitRuntimePrivatePCH.h"
#include "Public/StaticMeshAssetActor.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStaticMeshAssetActor() {}
// Cross Module References
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_AStaticMeshAssetActor_NoRegister();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_AStaticMeshAssetActor();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_AssetToolKitRuntime();
// End Cross Module References
	void AStaticMeshAssetActor::StaticRegisterNativesAStaticMeshAssetActor()
	{
	}
	UClass* Z_Construct_UClass_AStaticMeshAssetActor_NoRegister()
	{
		return AStaticMeshAssetActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AStaticMeshAssetActor()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AStaticMeshActor();
			Z_Construct_UPackage__Script_AssetToolKitRuntime();
			OuterClass = AStaticMeshAssetActor::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				static TCppClassTypeInfo<TCppClassTypeTraits<AStaticMeshAssetActor> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Input"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("StaticMeshAssetActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/StaticMeshAssetActor.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStaticMeshAssetActor, 3211702879);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStaticMeshAssetActor(Z_Construct_UClass_AStaticMeshAssetActor, &AStaticMeshAssetActor::StaticClass, TEXT("/Script/AssetToolKitRuntime"), TEXT("AStaticMeshAssetActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStaticMeshAssetActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
