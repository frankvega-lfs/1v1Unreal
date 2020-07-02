// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Door.h"
//#include "PlayerStateF.h"
#include "GameModeF.generated.h"

/**
 * 
 */

// restar vida en el player state. llama al metodo kill de player state. puede destruir el actor. mecanica de respawn.
UCLASS()
class AGameModeF : public AGameMode
{
	GENERATED_BODY()

		

protected:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		TArray<TSoftObjectPtr<UWorld>> Maps;

	UPROPERTY(Transient)
		TArray<class ADoor*> CurrentDoors;

	UPROPERTY(EditAnywhere)
		int enemiesLeft;

	FTimerHandle RespawnTimerHandle;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> MyDefaultPawnClass;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	
	//void RespawnPlayer(APlayerStateF* PlayerState, APlayerController* PlayerController);
public:

	UPROPERTY(EditAnywhere)
		int enemiesToKill;

	UPROPERTY(EditAnywhere)
	float RespawnTime;

	void ReduceLives(APawn* player);
	void ReduceLives(AActor* test);
	void CheckEnemiesKilled();
	void ChangeMap(FString MapName);

	void Respawn(APlayerController* player);
};
