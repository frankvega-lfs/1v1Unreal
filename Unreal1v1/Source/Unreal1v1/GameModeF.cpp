// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeF.h"
#include "GameFramework/GameState.h"
#include "FPSCharacter.h"
/*#include "HealthComponentFrank.h"
#include "PlayerStateF.h"*/
#include "TimerManager.h"
//#include "Components/BoxComponent.h"
#include "Engine/World.h"

void AGameModeF::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	DefaultPawnClass = MyDefaultPawnClass;
}

/*void AGameModeF::ReduceLives(APawn* player)
{
	APlayerStateF* PlayerState = Cast<APlayerStateF>(player->GetPlayerState());
	APlayerController* PlayerController = Cast<APlayerController>(PlayerState->GetPawn()->GetController());
	PlayerState->Kill();
	PlayerState->GetPawn()->Destroy();

	FTimerDelegate TimerDelegate;

	TimerDelegate.BindUObject(this, &ThisClass::RespawnPlayer, PlayerState, PlayerController);

	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, TimerDelegate, RespawnTime, false);
	
	UE_LOG(LogTemp, Warning, TEXT("REducing lives... %i"), PlayerState->Lives);
}*/

/*void AGameModeF::RespawnPlayer(APlayerStateF* PlayerState, APlayerController* PlayerController)
{
	UE_LOG(LogTemp, Warning, TEXT("Respawn...."));
	if (PlayerState->Lives >= 0)
	{
		RestartPlayer(PlayerController);
	}
	
}*/