// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AStaticMeshAssetActor;
#ifdef ASSETTOOLKITRUNTIME_SceneAssetManager_generated_h
#error "SceneAssetManager.generated.h already included, missing '#pragma once' in SceneAssetManager.h"
#endif
#define ASSETTOOLKITRUNTIME_SceneAssetManager_generated_h

#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_13_GENERATED_BODY \
	friend ASSETTOOLKITRUNTIME_API class UScriptStruct* Z_Construct_UScriptStruct_FSceneAssetInfo(); \
	ASSETTOOLKITRUNTIME_API static class UScriptStruct* StaticStruct();


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDoAsyncAssetChange) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DoAsyncAssetChange(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUnloadSceneAsset) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UnloadSceneAsset(Z_Param_Id); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execChangeSceneAsset) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_OldAssetId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewAssetId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->ChangeSceneAsset(Z_Param_OldAssetId,Z_Param_NewAssetId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadAssetPackage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->LoadAssetPackage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadSceneAssetToActor) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Id); \
		P_GET_OBJECT(AStaticMeshAssetActor,Z_Param_AssetActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->LoadSceneAssetToActor(Z_Param_Id,Z_Param_AssetActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadSceneAsset) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->LoadSceneAsset(Z_Param_Id); \
		P_NATIVE_END; \
	}


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDoAsyncAssetChange) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DoAsyncAssetChange(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execUnloadSceneAsset) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UnloadSceneAsset(Z_Param_Id); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execChangeSceneAsset) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_OldAssetId); \
		P_GET_PROPERTY(UIntProperty,Z_Param_NewAssetId); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->ChangeSceneAsset(Z_Param_OldAssetId,Z_Param_NewAssetId); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadAssetPackage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->LoadAssetPackage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadSceneAssetToActor) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Id); \
		P_GET_OBJECT(AStaticMeshAssetActor,Z_Param_AssetActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->LoadSceneAssetToActor(Z_Param_Id,Z_Param_AssetActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadSceneAsset) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Id); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->LoadSceneAsset(Z_Param_Id); \
		P_NATIVE_END; \
	}


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASceneAssetManager(); \
	friend ASSETTOOLKITRUNTIME_API class UClass* Z_Construct_UClass_ASceneAssetManager(); \
public: \
	DECLARE_CLASS(ASceneAssetManager, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/AssetToolKitRuntime"), NO_API) \
	DECLARE_SERIALIZER(ASceneAssetManager) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_INCLASS \
private: \
	static void StaticRegisterNativesASceneAssetManager(); \
	friend ASSETTOOLKITRUNTIME_API class UClass* Z_Construct_UClass_ASceneAssetManager(); \
public: \
	DECLARE_CLASS(ASceneAssetManager, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/AssetToolKitRuntime"), NO_API) \
	DECLARE_SERIALIZER(ASceneAssetManager) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASceneAssetManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASceneAssetManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASceneAssetManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASceneAssetManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASceneAssetManager(ASceneAssetManager&&); \
	NO_API ASceneAssetManager(const ASceneAssetManager&); \
public:


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASceneAssetManager(ASceneAssetManager&&); \
	NO_API ASceneAssetManager(const ASceneAssetManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASceneAssetManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASceneAssetManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASceneAssetManager)


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_PRIVATE_PROPERTY_OFFSET
#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_24_PROLOG
#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_PRIVATE_PROPERTY_OFFSET \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_RPC_WRAPPERS \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_INCLASS \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_PRIVATE_PROPERTY_OFFSET \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_INCLASS_NO_PURE_DECLS \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_SceneAssetManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
