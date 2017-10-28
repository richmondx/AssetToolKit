// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/AssetToolKitRuntimePrivatePCH.h"
#include "Public/SceneAssetManager.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSceneAssetManager() {}
// Cross Module References
	ASSETTOOLKITRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FSceneAssetInfo();
	UPackage* Z_Construct_UPackage__Script_AssetToolKitRuntime();
	ASSETTOOLKITRUNTIME_API UFunction* Z_Construct_UFunction_ASceneAssetManager_ChangeSceneAsset();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_ASceneAssetManager();
	ASSETTOOLKITRUNTIME_API UFunction* Z_Construct_UFunction_ASceneAssetManager_DoAsyncAssetChange();
	ASSETTOOLKITRUNTIME_API UFunction* Z_Construct_UFunction_ASceneAssetManager_LoadAssetPackage();
	ASSETTOOLKITRUNTIME_API UFunction* Z_Construct_UFunction_ASceneAssetManager_LoadSceneAsset();
	ASSETTOOLKITRUNTIME_API UFunction* Z_Construct_UFunction_ASceneAssetManager_LoadSceneAssetToActor();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_AStaticMeshAssetActor_NoRegister();
	ASSETTOOLKITRUNTIME_API UFunction* Z_Construct_UFunction_ASceneAssetManager_UnloadSceneAsset();
	ASSETTOOLKITRUNTIME_API UClass* Z_Construct_UClass_ASceneAssetManager_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
class UScriptStruct* FSceneAssetInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ASSETTOOLKITRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FSceneAssetInfo_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSceneAssetInfo, Z_Construct_UPackage__Script_AssetToolKitRuntime(), TEXT("SceneAssetInfo"), sizeof(FSceneAssetInfo), Get_Z_Construct_UScriptStruct_FSceneAssetInfo_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSceneAssetInfo(FSceneAssetInfo::StaticStruct, TEXT("/Script/AssetToolKitRuntime"), TEXT("SceneAssetInfo"), false, nullptr, nullptr);
static struct FScriptStruct_AssetToolKitRuntime_StaticRegisterNativesFSceneAssetInfo
{
	FScriptStruct_AssetToolKitRuntime_StaticRegisterNativesFSceneAssetInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SceneAssetInfo")),new UScriptStruct::TCppStructOps<FSceneAssetInfo>);
	}
} ScriptStruct_AssetToolKitRuntime_StaticRegisterNativesFSceneAssetInfo;
	UScriptStruct* Z_Construct_UScriptStruct_FSceneAssetInfo()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_AssetToolKitRuntime();
		extern uint32 Get_Z_Construct_UScriptStruct_FSceneAssetInfo_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SceneAssetInfo"), sizeof(FSceneAssetInfo), Get_Z_Construct_UScriptStruct_FSceneAssetInfo_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("SceneAssetInfo"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FSceneAssetInfo>, EStructFlags(0x00000001));
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/SceneAssetManager.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSceneAssetInfo_CRC() { return 2344582354U; }
	void ASceneAssetManager::StaticRegisterNativesASceneAssetManager()
	{
		UClass* Class = ASceneAssetManager::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "ChangeSceneAsset", (Native)&ASceneAssetManager::execChangeSceneAsset },
			{ "DoAsyncAssetChange", (Native)&ASceneAssetManager::execDoAsyncAssetChange },
			{ "LoadAssetPackage", (Native)&ASceneAssetManager::execLoadAssetPackage },
			{ "LoadSceneAsset", (Native)&ASceneAssetManager::execLoadSceneAsset },
			{ "LoadSceneAssetToActor", (Native)&ASceneAssetManager::execLoadSceneAssetToActor },
			{ "UnloadSceneAsset", (Native)&ASceneAssetManager::execUnloadSceneAsset },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_ASceneAssetManager_ChangeSceneAsset()
	{
		struct SceneAssetManager_eventChangeSceneAsset_Parms
		{
			int32 OldAssetId;
			int32 NewAssetId;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASceneAssetManager();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ChangeSceneAsset"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SceneAssetManager_eventChangeSceneAsset_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SceneAssetManager_eventChangeSceneAsset_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SceneAssetManager_eventChangeSceneAsset_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SceneAssetManager_eventChangeSceneAsset_Parms), sizeof(bool), true);
			UProperty* NewProp_NewAssetId = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("NewAssetId"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(NewAssetId, SceneAssetManager_eventChangeSceneAsset_Parms), 0x0010000000000080);
			UProperty* NewProp_OldAssetId = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OldAssetId"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(OldAssetId, SceneAssetManager_eventChangeSceneAsset_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AssetLoad"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SceneAssetManager.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x6307\x5b9a\x66f4\x6539\x5bf9\x8c61"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASceneAssetManager_DoAsyncAssetChange()
	{
		UObject* Outer = Z_Construct_UClass_ASceneAssetManager();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("DoAsyncAssetChange"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AssetLoad"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SceneAssetManager.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x5f02\x6b65\x66f4\x65b0\x5bf9\x8c61"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASceneAssetManager_LoadAssetPackage()
	{
		struct SceneAssetManager_eventLoadAssetPackage_Parms
		{
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASceneAssetManager();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("LoadAssetPackage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SceneAssetManager_eventLoadAssetPackage_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SceneAssetManager_eventLoadAssetPackage_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SceneAssetManager_eventLoadAssetPackage_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SceneAssetManager_eventLoadAssetPackage_Parms), sizeof(bool), true);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AssetLoad"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SceneAssetManager.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASceneAssetManager_LoadSceneAsset()
	{
		struct SceneAssetManager_eventLoadSceneAsset_Parms
		{
			int32 Id;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASceneAssetManager();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("LoadSceneAsset"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SceneAssetManager_eventLoadSceneAsset_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SceneAssetManager_eventLoadSceneAsset_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SceneAssetManager_eventLoadSceneAsset_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SceneAssetManager_eventLoadSceneAsset_Parms), sizeof(bool), true);
			UProperty* NewProp_Id = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Id"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Id, SceneAssetManager_eventLoadSceneAsset_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AssetLoad"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SceneAssetManager.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x6307\x5b9a\x52a0\x8f7d\x5bf9\x8c61"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASceneAssetManager_LoadSceneAssetToActor()
	{
		struct SceneAssetManager_eventLoadSceneAssetToActor_Parms
		{
			int32 Id;
			AStaticMeshAssetActor* AssetActor;
			bool ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_ASceneAssetManager();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("LoadSceneAssetToActor"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SceneAssetManager_eventLoadSceneAssetToActor_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, SceneAssetManager_eventLoadSceneAssetToActor_Parms);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, SceneAssetManager_eventLoadSceneAssetToActor_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, SceneAssetManager_eventLoadSceneAssetToActor_Parms), sizeof(bool), true);
			UProperty* NewProp_AssetActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("AssetActor"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(AssetActor, SceneAssetManager_eventLoadSceneAssetToActor_Parms), 0x0010000000000080, Z_Construct_UClass_AStaticMeshAssetActor_NoRegister());
			UProperty* NewProp_Id = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Id"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Id, SceneAssetManager_eventLoadSceneAssetToActor_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AssetLoad"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SceneAssetManager.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x6307\x5b9a\x52a0\x8f7d\x8d44\x6e90\x5230\x5bf9\x5e94\x7684\x5b9e\x4f8b"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASceneAssetManager_UnloadSceneAsset()
	{
		struct SceneAssetManager_eventUnloadSceneAsset_Parms
		{
			int32 Id;
		};
		UObject* Outer = Z_Construct_UClass_ASceneAssetManager();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("UnloadSceneAsset"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(SceneAssetManager_eventUnloadSceneAsset_Parms));
			UProperty* NewProp_Id = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Id"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Id, SceneAssetManager_eventUnloadSceneAsset_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("AssetLoad"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SceneAssetManager.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x6307\x5b9a\x5378\x8f7d\x5bf9\x8c61"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASceneAssetManager_NoRegister()
	{
		return ASceneAssetManager::StaticClass();
	}
	UClass* Z_Construct_UClass_ASceneAssetManager()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_AssetToolKitRuntime();
			OuterClass = ASceneAssetManager::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_ASceneAssetManager_ChangeSceneAsset());
				OuterClass->LinkChild(Z_Construct_UFunction_ASceneAssetManager_DoAsyncAssetChange());
				OuterClass->LinkChild(Z_Construct_UFunction_ASceneAssetManager_LoadAssetPackage());
				OuterClass->LinkChild(Z_Construct_UFunction_ASceneAssetManager_LoadSceneAsset());
				OuterClass->LinkChild(Z_Construct_UFunction_ASceneAssetManager_LoadSceneAssetToActor());
				OuterClass->LinkChild(Z_Construct_UFunction_ASceneAssetManager_UnloadSceneAsset());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneAssetManager_ChangeSceneAsset(), "ChangeSceneAsset"); // 2971329185
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneAssetManager_DoAsyncAssetChange(), "DoAsyncAssetChange"); // 4111573952
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneAssetManager_LoadAssetPackage(), "LoadAssetPackage"); // 2847261586
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneAssetManager_LoadSceneAsset(), "LoadSceneAsset"); // 2730892903
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneAssetManager_LoadSceneAssetToActor(), "LoadSceneAssetToActor"); // 310015666
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ASceneAssetManager_UnloadSceneAsset(), "UnloadSceneAsset"); // 1548158289
				static TCppClassTypeInfo<TCppClassTypeTraits<ASceneAssetManager> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SceneAssetManager.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/SceneAssetManager.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("DECLARE_DELEGATE_TwoParams(FCustomStreamableDelegate, int32 OldIndex, int32 NewIndex)"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASceneAssetManager, 4175126874);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASceneAssetManager(Z_Construct_UClass_ASceneAssetManager, &ASceneAssetManager::StaticClass, TEXT("/Script/AssetToolKitRuntime"), TEXT("ASceneAssetManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASceneAssetManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
