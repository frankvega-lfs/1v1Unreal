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

void AGameModeF::ReduceLives(APawn* player)
{
	/*APlayerStateF* PlayerState = Cast<APlayerStateF>(player->GetPlayerState());
	APlayerController* PlayerController = Cast<APlayerController>(PlayerState->GetPawn()->GetController());
	PlayerState->Kill();
	PlayerState->GetPawn()->Destroy();*/

	player->Destroy(); //for the moment.

	FTimerDelegate TimerDelegate;

	//TimerDelegate.BindUObject(this, &ThisClass::RespawnPlayer, PlayerState, PlayerController);

	//GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, TimerDelegate, RespawnTime, false);
	
	//UE_LOG(LogTemp, Warning, TEXT("REducing lives... %i"), PlayerState->Lives);
}

void AGameModeF::ReduceLives(AActor* test)
{
	/*APlayerStateF* PlayerState = Cast<APlayerStateF>(player->GetPlayerState());
	APlayerController* PlayerController = Cast<APlayerController>(PlayerState->GetPawn()->GetController());
	PlayerState->Kill();
	PlayerState->GetPawn()->Destroy();*/

	test->Destroy(); //for the moment.

	FTimerDelegate TimerDelegate;

	//TimerDelegate.BindUObject(this, &ThisClass::RespawnPlayer, PlayerState, PlayerController);

	//GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, TimerDelegate, RespawnTime, false);

	//UE_LOG(LogTemp, Warning, TEXT("REducing lives... %i"), PlayerState->Lives);
}

void AGameModeF::Respawn(AController* player)
{
	UE_LOG(LogTemp, Warning, TEXT("Respawn...."));

	if (player) {
		FVector Location = FVector(-1500.0f, 90.0f, 310.0f); //TODO CHANGE THIS DINAMICALLY
		if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, FRotator::ZeroRotator)){
			player->Possess(Pawn);
		}
	}
}