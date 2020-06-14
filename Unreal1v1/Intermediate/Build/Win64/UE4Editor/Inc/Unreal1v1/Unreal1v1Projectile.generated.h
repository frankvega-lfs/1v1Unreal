// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef UNREAL1V1_Unreal1v1Projectile_generated_h
#error "Unreal1v1Projectile.generated.h already included, missing '#pragma once' in Unreal1v1Projectile.h"
#endif
#define UNREAL1V1_Unreal1v1Projectile_generated_h

#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_SPARSE_DATA
#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAUnreal1v1Projectile(); \
	friend struct Z_Construct_UClass_AUnreal1v1Projectile_Statics; \
public: \
	DECLARE_CLASS(AUnreal1v1Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Unreal1v1"), NO_API) \
	DECLARE_SERIALIZER(AUnreal1v1Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAUnreal1v1Projectile(); \
	friend struct Z_Construct_UClass_AUnreal1v1Projectile_Statics; \
public: \
	DECLARE_CLASS(AUnreal1v1Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Unreal1v1"), NO_API) \
	DECLARE_SERIALIZER(AUnreal1v1Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AUnreal1v1Projectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AUnreal1v1Projectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUnreal1v1Projectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUnreal1v1Projectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUnreal1v1Projectile(AUnreal1v1Projectile&&); \
	NO_API AUnreal1v1Projectile(const AUnreal1v1Projectile&); \
public:


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AUnreal1v1Projectile(AUnreal1v1Projectile&&); \
	NO_API AUnreal1v1Projectile(const AUnreal1v1Projectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUnreal1v1Projectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUnreal1v1Projectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AUnreal1v1Projectile)


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AUnreal1v1Projectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AUnreal1v1Projectile, ProjectileMovement); }


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_9_PROLOG
#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_SPARSE_DATA \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_RPC_WRAPPERS \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_INCLASS \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_PRIVATE_PROPERTY_OFFSET \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_SPARSE_DATA \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_INCLASS_NO_PURE_DECLS \
	Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREAL1V1_API UClass* StaticClass<class AUnreal1v1Projectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal1v1_Source_Unreal1v1_Unreal1v1Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
