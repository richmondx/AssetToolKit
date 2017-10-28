// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/AssetToolKitRuntimePrivatePCH.h"
#include "Public/AssetExecutePakFile.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssetExecutePakFile() {}
// Cross Module References
	ASSETTOOLKITRUNTIME_API UFunction* Z_Construct_UFunction_UAssetExecutePakFile_ExecutePakFile();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_UAssetExecutePakFile();
	ASSETTOOLKITRUNTIME_API UFunction* Z_Construct_UFunction_UAssetExecutePakFile_SetSceneManage();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_ASceneAssetManager_NoRegister();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_UAssetExecutePakFile_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_AssetToolKitRuntime();
// End Cross Module References
	void UAssetExecutePakFile::StaticRegisterNativesUAssetExecutePakFile()
	{
		UClass* Class = UAssetExecutePakFile::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "ExecutePakFile", (Native)&UAssetExecutePakFile::execExecutePakFile },
			{ "SetSceneManage", (Native)&UAssetExecutePakFile::execSetSceneManage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_UAssetExecutePakFile_ExecutePakFile()
	{
		UObject* Outer = Z_Construct_UClass_UAssetExecutePakFile();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ExecutePakFile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Pak"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/AssetExecutePakFile.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UAssetExecutePakFile_SetSceneManage()
	{
		struct AssetExecutePakFile_eventSetSceneManage_Parms
		{
			ASceneAssetManager* Man;
		};
		UObject* Outer = Z_Construct_UClass_UAssetExecutePakFile();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SetSceneManage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(AssetExecutePakFile_eventSetSceneManage_Parms));
			UProperty* NewProp_Man = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Man"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Man, AssetExecutePakFile_eventSetSceneManage_Parms), 0x0010000000000080, Z_Construct_UClass_ASceneAssetManager_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Pak"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/AssetExecutePakFile.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAssetExecutePakFile_NoRegister()
	{
		return UAssetExecutePakFile::StaticClass();
	}
	UClass* Z_Construct_UClass_UAssetExecutePakFile()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UBlueprintFunctionLibrary();
			Z_Construct_UPackage__Script_AssetToolKitRuntime();
			OuterClass = UAssetExecutePakFile::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100080u;

				OuterClass->LinkChild(Z_Construct_UFunction_UAssetExecutePakFile_ExecutePakFile());
				OuterClass->LinkChild(Z_Construct_UFunction_UAssetExecutePakFile_SetSceneManage());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UAssetExecutePakFile_ExecutePakFile(), "ExecutePakFile"); // 2342307874
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UAssetExecutePakFile_SetSceneManage(), "SetSceneManage"); // 2721267596
				static TCppClassTypeInfo<TCppClassTypeTraits<UAssetExecutePakFile> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("AssetExecutePakFile.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/AssetExecutePakFile.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAssetExecutePakFile, 782713487);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAssetExecutePakFile(Z_Construct_UClass_UAssetExecutePakFile, &UAssetExecutePakFile::StaticClass, TEXT("/Script/AssetToolKitRuntime"), TEXT("UAssetExecutePakFile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetExecutePakFile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
