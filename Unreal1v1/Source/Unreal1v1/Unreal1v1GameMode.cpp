// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Unreal1v1GameMode.h"
#include "Unreal1v1HUD.h"
#include "Unreal1v1Character.h"
#include "UObject/ConstructorHelpers.h"

AUnreal1v1GameMode::AUnreal1v1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;*/

	// use our custom HUD class
	//HUDClass = AUnreal1v1HUD::StaticClass();
}
