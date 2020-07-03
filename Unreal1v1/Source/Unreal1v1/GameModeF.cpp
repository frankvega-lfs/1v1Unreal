// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeF.h"
#include "GameFramework/GameState.h"
#include "FPSCharacter.h"
#include "kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/World.h"

void AGameModeF::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	DefaultPawnClass = MyDefaultPawnClass;
	enemiesLeft = enemiesToKill;

	TArray<AActor*> Doors;

	UGameplayStatics::GetAllActorsOfClass(this, ADoor::StaticClass(), Doors);


	for (AActor* Actor : Doors)
	{
		ADoor* ActorDoor = Cast<ADoor>(Actor);
		CurrentDoors.Add(ActorDoor);
	}

	if (CurrentDoors.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Succesfully added doors!"));
	}
}

void AGameModeF::ReduceLives(APawn* Player)
{
	UE_LOG(LogTemp, Warning, TEXT("Player Death!"));

	APlayerController* PlayerController = Cast<APlayerController>(Player->GetController());
	APlayerStateFPS* PlayerState = Cast<APlayerStateFPS>(Player->GetPlayerState());
	

	if (PlayerController != nullptr)
	{
		PlayerState->Kill();

		Player->Destroy();

		if (PlayerState->Lives > 0)
		{
			FTimerDelegate TimerDelegate;

			TimerDelegate.BindUObject(this, &ThisClass::Respawn, PlayerState, PlayerController);

			GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, TimerDelegate, RespawnTime, false);
		}
		else
		{
			FTimerDelegate TimerDelegate2;

			TimerDelegate2.BindUObject(this, &ThisClass::ChangeMap, LossMapName);

			GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle2, TimerDelegate2, RespawnTime, false);
		}
		
	}
	else
	{
		Player->Destroy();
	}
}

void AGameModeF::CheckEnemiesKilled()
{
	enemiesLeft--;

	if (enemiesLeft <= 0)
	{
		enemiesLeft = 0;
		if (CurrentDoors.Num() > 0)
		{
			for (size_t i = 0; i < CurrentDoors.Num(); i++)
			{
				CurrentDoors[i]->Destroy();
			}		

			CurrentDoors.Empty();
			UE_LOG(LogTemp, Warning, TEXT("Succesfully DELETED doors!"));
		}
	}
}

void AGameModeF::ChangeMap(FString MapName)
{
	for (int i = 0; i < Maps.Num(); i++)
	{
		FString text = Maps[i].ToSoftObjectPath().GetSubPathString();
		FString text2 = Maps[i].ToSoftObjectPath().GetAssetName();

		if (MapName == text + text2)
		{
			GetWorld()->ServerTravel(MapName);
		}
	}
}

void AGameModeF::Respawn(APlayerStateFPS* PlayerState, APlayerController* PlayerController)
{
	UE_LOG(LogTemp, Warning, TEXT("Respawn...."));

	if (PlayerState->Lives > 0)
	{
		RestartPlayer(PlayerController);
	}
}