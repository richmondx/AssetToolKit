// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/AssetToolKitRuntimePrivatePCH.h"
#include "Public/GameSingleton.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameSingleton() {}
// Cross Module References
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_UGameSingleton_NoRegister();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_UGameSingleton();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_AssetToolKitRuntime();
// End Cross Module References
	void UGameSingleton::StaticRegisterNativesUGameSingleton()
	{
	}
	UClass* Z_Construct_UClass_UGameSingleton_NoRegister()
	{
		return UGameSingleton::StaticClass();
	}
	UClass* Z_Construct_UClass_UGameSingleton()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_AssetToolKitRuntime();
			OuterClass = UGameSingleton::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100280u;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<UGameSingleton> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("GameSingleton.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/GameSingleton.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameSingleton, 473897513);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameSingleton(Z_Construct_UClass_UGameSingleton, &UGameSingleton::StaticClass, TEXT("/Script/AssetToolKitRuntime"), TEXT("UGameSingleton"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameSingleton);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
