// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ASceneAssetManager;
#ifdef ASSETTOOLKITRUNTIME_AssetExecutePakFile_generated_h
#error "AssetExecutePakFile.generated.h already included, missing '#pragma once' in AssetExecutePakFile.h"
#endif
#define ASSETTOOLKITRUNTIME_AssetExecutePakFile_generated_h

#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetSceneManage) \
	{ \
		P_GET_OBJECT(ASceneAssetManager,Z_Param_Man); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAssetExecutePakFile::SetSceneManage(Z_Param_Man); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecutePakFile) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAssetExecutePakFile::ExecutePakFile(); \
		P_NATIVE_END; \
	}


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetSceneManage) \
	{ \
		P_GET_OBJECT(ASceneAssetManager,Z_Param_Man); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAssetExecutePakFile::SetSceneManage(Z_Param_Man); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExecutePakFile) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UAssetExecutePakFile::ExecutePakFile(); \
		P_NATIVE_END; \
	}


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAssetExecutePakFile(); \
	friend ASSETTOOLKITRUNTIME_API class UClass* Z_Construct_UClass_UAssetExecutePakFile(); \
public: \
	DECLARE_CLASS(UAssetExecutePakFile, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/AssetToolKitRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAssetExecutePakFile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUAssetExecutePakFile(); \
	friend ASSETTOOLKITRUNTIME_API class UClass* Z_Construct_UClass_UAssetExecutePakFile(); \
public: \
	DECLARE_CLASS(UAssetExecutePakFile, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/AssetToolKitRuntime"), NO_API) \
	DECLARE_SERIALIZER(UAssetExecutePakFile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAssetExecutePakFile(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAssetExecutePakFile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAssetExecutePakFile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAssetExecutePakFile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAssetExecutePakFile(UAssetExecutePakFile&&); \
	NO_API UAssetExecutePakFile(const UAssetExecutePakFile&); \
public:


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAssetExecutePakFile(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAssetExecutePakFile(UAssetExecutePakFile&&); \
	NO_API UAssetExecutePakFile(const UAssetExecutePakFile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAssetExecutePakFile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAssetExecutePakFile); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAssetExecutePakFile)


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_PRIVATE_PROPERTY_OFFSET
#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_12_PROLOG
#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_PRIVATE_PROPERTY_OFFSET \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_RPC_WRAPPERS \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_INCLASS \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_PRIVATE_PROPERTY_OFFSET \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_INCLASS_NO_PURE_DECLS \
	Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project417_Plugins_AssetToolKit_Source_AssetToolKitRuntime_Public_AssetExecutePakFile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
