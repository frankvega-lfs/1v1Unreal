// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Door.h"
#include "PlayerStateFPS.h"
#include "GameModeF.generated.h"

// restar vida en el player state. llama al metodo kill de player state. puede destruir el actor. mecanica de respawn.
UCLASS()
class AGameModeF : public AGameMode
{
	GENERATED_BODY()

		

protected:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TArray<TSoftObjectPtr<UWorld>> Maps;

	UPROPERTY(EditAnywhere)
		FString LossMapName;

	UPROPERTY(Transient)
		TArray<class ADoor*> CurrentDoors;

	

	FTimerHandle RespawnTimerHandle;
	FTimerHandle RespawnTimerHandle2;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> MyDefaultPawnClass;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int enemiesLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int enemiesToKill;

	UPROPERTY(EditAnywhere)
	float RespawnTime;

	void ReduceLives(APawn* Player);
	void CheckEnemiesKilled();
	void ChangeMap(FString MapName);

	void Respawn(APlayerStateFPS* PlayerState, APlayerController* PlayerController);
};
