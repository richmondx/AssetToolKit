// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/AssetToolKitPrivatePCH.h"
#include "Public/AssetToolFactory.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssetToolFactory() {}
// Cross Module References
	ASSETTOOLKIT_API UClass* Z_Construct_UClass_UAssetToolFactory_NoRegister();
	ASSETTOOLKIT_API UClass* Z_Construct_UClass_UAssetToolFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_AssetToolKit();
// End Cross Module References
	void UAssetToolFactory::StaticRegisterNativesUAssetToolFactory()
	{
	}
	UClass* Z_Construct_UClass_UAssetToolFactory_NoRegister()
	{
		return UAssetToolFactory::StaticClass();
	}
	UClass* Z_Construct_UClass_UAssetToolFactory()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UFactory();
			Z_Construct_UPackage__Script_AssetToolKit();
			OuterClass = UAssetToolFactory::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100080u;


				static TCppClassTypeInfo<TCppClassTypeTraits<UAssetToolFactory> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("AssetToolFactory.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/AssetToolFactory.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAssetToolFactory, 2924679195);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAssetToolFactory(Z_Construct_UClass_UAssetToolFactory, &UAssetToolFactory::StaticClass, TEXT("/Script/AssetToolKit"), TEXT("UAssetToolFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetToolFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
