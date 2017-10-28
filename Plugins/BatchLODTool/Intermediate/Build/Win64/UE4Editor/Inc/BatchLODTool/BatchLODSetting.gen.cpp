// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/BatchLODSetting.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBatchLODSetting() {}
// Cross Module References
	BATCHLODTOOL_API UClass* Z_Construct_UClass_UBatchLODSetting_NoRegister();
	BATCHLODTOOL_API UClass* Z_Construct_UClass_UBatchLODSetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_BatchLODTool();
// End Cross Module References
	void UBatchLODSetting::StaticRegisterNativesUBatchLODSetting()
	{
	}
	UClass* Z_Construct_UClass_UBatchLODSetting_NoRegister()
	{
		return UBatchLODSetting::StaticClass();
	}
	UClass* Z_Construct_UClass_UBatchLODSetting()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_BatchLODTool();
			OuterClass = UBatchLODSetting::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100086u;


				UProperty* NewProp_Percent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Percent"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(Percent, UBatchLODSetting), 0x0010000000004001);
				UProperty* NewProp_Percent_Inner = new(EC_InternalUseOnlyConstructor, NewProp_Percent, TEXT("Percent"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000004000);
				OuterClass->ClassConfigName = FName(TEXT("Engine"));
				static TCppClassTypeInfo<TCppClassTypeTraits<UBatchLODSetting> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("DisplayName"), TEXT("BatchLOD"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BatchLODSetting.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/BatchLODSetting.h"));
				MetaData->SetValue(NewProp_Percent, TEXT("Category"), TEXT("LOD-Percent%1 - %100"));
				MetaData->SetValue(NewProp_Percent, TEXT("ModuleRelativePath"), TEXT("Public/BatchLODSetting.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBatchLODSetting, 1900664021);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBatchLODSetting(Z_Construct_UClass_UBatchLODSetting, &UBatchLODSetting::StaticClass, TEXT("/Script/BatchLODTool"), TEXT("UBatchLODSetting"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBatchLODSetting);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
