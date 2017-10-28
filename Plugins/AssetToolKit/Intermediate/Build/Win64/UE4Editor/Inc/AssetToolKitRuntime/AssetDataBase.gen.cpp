// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/AssetToolKitRuntimePrivatePCH.h"
#include "Public/AssetDataBase.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssetDataBase() {}
// Cross Module References
	ASSETTOOLKITRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FAssetDataInfo();
	UPackage* Z_Construct_UPackage__Script_AssetToolKitRuntime();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_UAssetDataBase_NoRegister();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_UAssetDataBase();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
// End Cross Module References
class UScriptStruct* FAssetDataInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ASSETTOOLKITRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FAssetDataInfo_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAssetDataInfo, Z_Construct_UPackage__Script_AssetToolKitRuntime(), TEXT("AssetDataInfo"), sizeof(FAssetDataInfo), Get_Z_Construct_UScriptStruct_FAssetDataInfo_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAssetDataInfo(FAssetDataInfo::StaticStruct, TEXT("/Script/AssetToolKitRuntime"), TEXT("AssetDataInfo"), false, nullptr, nullptr);
static struct FScriptStruct_AssetToolKitRuntime_StaticRegisterNativesFAssetDataInfo
{
	FScriptStruct_AssetToolKitRuntime_StaticRegisterNativesFAssetDataInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AssetDataInfo")),new UScriptStruct::TCppStructOps<FAssetDataInfo>);
	}
} ScriptStruct_AssetToolKitRuntime_StaticRegisterNativesFAssetDataInfo;
	UScriptStruct* Z_Construct_UScriptStruct_FAssetDataInfo()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_AssetToolKitRuntime();
		extern uint32 Get_Z_Construct_UScriptStruct_FAssetDataInfo_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AssetDataInfo"), sizeof(FAssetDataInfo), Get_Z_Construct_UScriptStruct_FAssetDataInfo_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("AssetDataInfo"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FAssetDataInfo>, EStructFlags(0x00000001));
			UProperty* NewProp_StaticMeshResource = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("StaticMeshResource"), RF_Public|RF_Transient|RF_MarkAsNative) UAssetObjectProperty(CPP_PROPERTY_BASE(StaticMeshResource, FAssetDataInfo), 0x0014000000000001, Z_Construct_UClass_UStaticMesh_NoRegister());
			UProperty* NewProp_MeshID = new(EC_InternalUseOnlyConstructor, ReturnStruct, TEXT("MeshID"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(MeshID, FAssetDataInfo), 0x0010000000000001);
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/AssetDataBase.h"));
			MetaData->SetValue(ReturnStruct, TEXT("ToolTip"), TEXT("\x8d44\x6e90"));
			MetaData->SetValue(NewProp_StaticMeshResource, TEXT("Category"), TEXT("DATA"));
			MetaData->SetValue(NewProp_StaticMeshResource, TEXT("ModuleRelativePath"), TEXT("Public/AssetDataBase.h"));
			MetaData->SetValue(NewProp_StaticMeshResource, TEXT("ToolTip"), TEXT("Related Asset"));
			MetaData->SetValue(NewProp_MeshID, TEXT("Category"), TEXT("DATA"));
			MetaData->SetValue(NewProp_MeshID, TEXT("ModuleRelativePath"), TEXT("Public/AssetDataBase.h"));
			MetaData->SetValue(NewProp_MeshID, TEXT("ToolTip"), TEXT("The Mesh ID"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAssetDataInfo_CRC() { return 2795338036U; }
	void UAssetDataBase::StaticRegisterNativesUAssetDataBase()
	{
	}
	UClass* Z_Construct_UClass_UAssetDataBase_NoRegister()
	{
		return UAssetDataBase::StaticClass();
	}
	UClass* Z_Construct_UClass_UAssetDataBase()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UDataAsset();
			Z_Construct_UPackage__Script_AssetToolKitRuntime();
			OuterClass = UAssetDataBase::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20100080u;


				UProperty* NewProp_MeshList = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MeshList"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(MeshList, UAssetDataBase), 0x0010000000000001);
				UProperty* NewProp_MeshList_Inner = new(EC_InternalUseOnlyConstructor, NewProp_MeshList, TEXT("MeshList"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UScriptStruct_FAssetDataInfo());
				static TCppClassTypeInfo<TCppClassTypeTraits<UAssetDataBase> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("AssetDataBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/AssetDataBase.h"));
				MetaData->SetValue(NewProp_MeshList, TEXT("Category"), TEXT("Model List"));
				MetaData->SetValue(NewProp_MeshList, TEXT("ModuleRelativePath"), TEXT("Public/AssetDataBase.h"));
				MetaData->SetValue(NewProp_MeshList, TEXT("ToolTip"), TEXT("Asset Info"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAssetDataBase, 3865056560);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAssetDataBase(Z_Construct_UClass_UAssetDataBase, &UAssetDataBase::StaticClass, TEXT("/Script/AssetToolKitRuntime"), TEXT("UAssetDataBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetDataBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
