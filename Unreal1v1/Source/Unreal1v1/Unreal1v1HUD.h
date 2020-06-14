// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Unreal1v1HUD.generated.h"

UCLASS()
class AUnreal1v1HUD : public AHUD
{
	GENERATED_BODY()

public:
	AUnreal1v1HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

