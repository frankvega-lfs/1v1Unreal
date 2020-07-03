// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PlayerStateFPS.h"
#include "GameModeF.generated.h"

class ADoor;

// restar vida en el player state. llama al metodo kill de player state. puede destruir el actor. mecanica de respawn.
UCLASS()
class AGameModeF : public AGameMode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int EnemiesLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int EnemiesToKill;

	UPROPERTY(EditAnywhere)
		float RespawnTime;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TArray<TSoftObjectPtr<UWorld>> Maps;

	UPROPERTY(EditAnywhere)
		FString LossMapName;

	UPROPERTY(Transient)
		TArray<class ADoor*> CurrentDoors;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> MyDefaultPawnClass;

	FTimerHandle RespawnTimerHandle;
	FTimerHandle ChangeMapTimerHandle;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
public:

	UFUNCTION()
		void ReduceLives(APawn* Player);

	UFUNCTION()
		void CheckEnemiesKilled();

	UFUNCTION()
		void ChangeMap(FString MapName);

	UFUNCTION()
		void Respawn(APlayerStateFPS* PlayerState, APlayerController* PlayerController);
};
