// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal1v1/Unreal1v1HUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnreal1v1HUD() {}
// Cross Module References
	UNREAL1V1_API UClass* Z_Construct_UClass_AUnreal1v1HUD_NoRegister();
	UNREAL1V1_API UClass* Z_Construct_UClass_AUnreal1v1HUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_Unreal1v1();
// End Cross Module References
	void AUnreal1v1HUD::StaticRegisterNativesAUnreal1v1HUD()
	{
	}
	UClass* Z_Construct_UClass_AUnreal1v1HUD_NoRegister()
	{
		return AUnreal1v1HUD::StaticClass();
	}
	struct Z_Construct_UClass_AUnreal1v1HUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUnreal1v1HUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_Unreal1v1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnreal1v1HUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Unreal1v1HUD.h" },
		{ "ModuleRelativePath", "Unreal1v1HUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUnreal1v1HUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnreal1v1HUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AUnreal1v1HUD_Statics::ClassParams = {
		&AUnreal1v1HUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AUnreal1v1HUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUnreal1v1HUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUnreal1v1HUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AUnreal1v1HUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AUnreal1v1HUD, 2595689384);
	template<> UNREAL1V1_API UClass* StaticClass<AUnreal1v1HUD>()
	{
		return AUnreal1v1HUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUnreal1v1HUD(Z_Construct_UClass_AUnreal1v1HUD, &AUnreal1v1HUD::StaticClass, TEXT("/Script/Unreal1v1"), TEXT("AUnreal1v1HUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnreal1v1HUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
