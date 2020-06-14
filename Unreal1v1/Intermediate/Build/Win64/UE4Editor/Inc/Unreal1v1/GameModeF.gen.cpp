// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal1v1/GameModeF.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameModeF() {}
// Cross Module References
	UNREAL1V1_API UClass* Z_Construct_UClass_AGameModeF_NoRegister();
	UNREAL1V1_API UClass* Z_Construct_UClass_AGameModeF();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_Unreal1v1();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
// End Cross Module References
	void AGameModeF::StaticRegisterNativesAGameModeF()
	{
	}
	UClass* Z_Construct_UClass_AGameModeF_NoRegister()
	{
		return AGameModeF::StaticClass();
	}
	struct Z_Construct_UClass_AGameModeF_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RespawnTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RespawnTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyDefaultPawnClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_MyDefaultPawnClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameModeF_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_Unreal1v1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameModeF_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */// restar vida en el player state. llama al metodo kill de player state. puede destruir el actor. mecanica de respawn.\n" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GameModeF.h" },
		{ "ModuleRelativePath", "GameModeF.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "// restar vida en el player state. llama al metodo kill de player state. puede destruir el actor. mecanica de respawn." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameModeF_Statics::NewProp_RespawnTime_MetaData[] = {
		{ "Category", "GameModeF" },
		{ "ModuleRelativePath", "GameModeF.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameModeF_Statics::NewProp_RespawnTime = { "RespawnTime", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameModeF, RespawnTime), METADATA_PARAMS(Z_Construct_UClass_AGameModeF_Statics::NewProp_RespawnTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGameModeF_Statics::NewProp_RespawnTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameModeF_Statics::NewProp_MyDefaultPawnClass_MetaData[] = {
		{ "Category", "GameModeF" },
		{ "ModuleRelativePath", "GameModeF.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGameModeF_Statics::NewProp_MyDefaultPawnClass = { "MyDefaultPawnClass", nullptr, (EPropertyFlags)0x0024080000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameModeF, MyDefaultPawnClass), Z_Construct_UClass_APawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AGameModeF_Statics::NewProp_MyDefaultPawnClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGameModeF_Statics::NewProp_MyDefaultPawnClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameModeF_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameModeF_Statics::NewProp_RespawnTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameModeF_Statics::NewProp_MyDefaultPawnClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameModeF_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameModeF>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameModeF_Statics::ClassParams = {
		&AGameModeF::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGameModeF_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGameModeF_Statics::PropPointers),
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGameModeF_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGameModeF_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameModeF()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameModeF_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameModeF, 2388240464);
	template<> UNREAL1V1_API UClass* StaticClass<AGameModeF>()
	{
		return AGameModeF::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameModeF(Z_Construct_UClass_AGameModeF, &AGameModeF::StaticClass, TEXT("/Script/Unreal1v1"), TEXT("AGameModeF"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameModeF);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
