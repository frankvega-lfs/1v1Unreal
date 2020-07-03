// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerStateFPS.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL1V1_API APlayerStateFPS : public APlayerState
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere)
		int MaxLives;

public:
	APlayerStateFPS();

	UPROPERTY(EditAnywhere)
		int Lives;

	void Kill();
	void SetMaxLives(int amount);
};
