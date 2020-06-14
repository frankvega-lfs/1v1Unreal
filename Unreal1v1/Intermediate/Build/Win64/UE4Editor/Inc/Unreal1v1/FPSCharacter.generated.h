// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef UNREAL1V1_FPSCharacter_generated_h
#error "FPSCharacter.generated.h already included, missing '#pragma once' in FPSCharacter.h"
#endif
#define UNREAL1V1_FPSCharacter_generated_h

#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_SPARSE_DATA
#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnDamageReceived) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnDamageReceived(Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnDamageReceived) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnDamageReceived(Z_Param_DamageCauser); \
		P_NATIVE_END; \
	}


#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend struct Z_Construct_UClass_AFPSCharacter_Statics; \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Unreal1v1"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter)


#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_INCLASS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend struct Z_Construct_UClass_AFPSCharacter_Statics; \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Unreal1v1"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter)


#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCharacter(AFPSCharacter&&); \
	NO_API AFPSCharacter(const AFPSCharacter&); \
public:


#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSCharacter(AFPSCharacter&&); \
	NO_API AFPSCharacter(const AFPSCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSCharacter)


#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BaseTurnRate() { return STRUCT_OFFSET(AFPSCharacter, BaseTurnRate); } \
	FORCEINLINE static uint32 __PPO__BaseLookUpRate() { return STRUCT_OFFSET(AFPSCharacter, BaseLookUpRate); } \
	FORCEINLINE static uint32 __PPO__SprintMultiplier() { return STRUCT_OFFSET(AFPSCharacter, SprintMultiplier); } \
	FORCEINLINE static uint32 __PPO__WalkSpeed() { return STRUCT_OFFSET(AFPSCharacter, WalkSpeed); } \
	FORCEINLINE static uint32 __PPO__OriginalWalkSpeed() { return STRUCT_OFFSET(AFPSCharacter, OriginalWalkSpeed); } \
	FORCEINLINE static uint32 __PPO__PlayerGun() { return STRUCT_OFFSET(AFPSCharacter, PlayerGun); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AFPSCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AFPSCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AFPSCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FireAnimation() { return STRUCT_OFFSET(AFPSCharacter, FireAnimation); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AFPSCharacter, FP_MuzzleLocation); }


#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_15_PROLOG
#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_PRIVATE_PROPERTY_OFFSET \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_SPARSE_DATA \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_RPC_WRAPPERS \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_INCLASS \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_PRIVATE_PROPERTY_OFFSET \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_SPARSE_DATA \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_INCLASS_NO_PURE_DECLS \
	Unreal1v1_Source_Unreal1v1_FPSCharacter_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREAL1V1_API UClass* StaticClass<class AFPSCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal1v1_Source_Unreal1v1_FPSCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
