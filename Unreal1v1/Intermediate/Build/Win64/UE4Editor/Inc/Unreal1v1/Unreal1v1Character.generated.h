// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREAL1V1_Unreal1v1Character_generated_h
#error "Unreal1v1Character.generated.h already included, missing '#pragma once' in Unreal1v1Character.h"
#endif
#define UNREAL1V1_Unreal1v1Character_generated_h

#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_SPARSE_DATA
#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_RPC_WRAPPERS
#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAUnreal1v1Character(); \
	friend struct Z_Construct_UClass_AUnreal1v1Character_Statics; \
public: \
	DECLARE_CLASS(AUnreal1v1Character, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Unreal1v1"), NO_API) \
	DECLARE_SERIALIZER(AUnreal1v1Character)


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAUnreal1v1Character(); \
	friend struct Z_Construct_UClass_AUnreal1v1Character_Statics; \
public: \
	DECLARE_CLASS(AUnreal1v1Character, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Unreal1v1"), NO_API) \
	DECLARE_SERIALIZER(AUnreal1v1Character)


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AUnreal1v1Character(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AUnreal1v1Character) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUnreal1v1Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUnreal1v1Character); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUnreal1v1Character(AUnreal1v1Character&&); \
	NO_API AUnreal1v1Character(const AUnreal1v1Character&); \
public:


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUnreal1v1Character(AUnreal1v1Character&&); \
	NO_API AUnreal1v1Character(const AUnreal1v1Character&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUnreal1v1Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUnreal1v1Character); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AUnreal1v1Character)


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AUnreal1v1Character, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AUnreal1v1Character, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AUnreal1v1Character, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AUnreal1v1Character, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AUnreal1v1Character, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AUnreal1v1Character, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AUnreal1v1Character, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AUnreal1v1Character, L_MotionController); }


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_11_PROLOG
#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_PRIVATE_PROPERTY_OFFSET \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_SPARSE_DATA \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_RPC_WRAPPERS \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_INCLASS \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_PRIVATE_PROPERTY_OFFSET \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_SPARSE_DATA \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_INCLASS_NO_PURE_DECLS \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREAL1V1_API UClass* StaticClass<class AUnreal1v1Character>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal1v1_Source_Unreal1v1_Unreal1v1Character_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
