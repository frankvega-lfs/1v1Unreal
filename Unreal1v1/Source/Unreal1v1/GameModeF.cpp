// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeF.h"
#include "GameFramework/GameState.h"
#include "FPSCharacter.h"
/*#include "HealthComponentFrank.h"
#include "PlayerStateF.h"*/
#include "kismet/GameplayStatics.h"
#include "TimerManager.h"
//#include "Components/BoxComponent.h"
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

void AGameModeF::ReduceLives(APawn* player)
{
	UE_LOG(LogTemp, Warning, TEXT("Player Death!"));

	APlayerController* PlayerController = Cast<APlayerController>(player->GetController());

	if (PlayerController != nullptr)
	{
		player->Destroy();

		FTimerDelegate TimerDelegate;

		TimerDelegate.BindUObject(this, &ThisClass::Respawn, PlayerController);

		GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, TimerDelegate, RespawnTime, false);
	}
	else
	{
		player->Destroy();
	}
}

void AGameModeF::ReduceLives(AActor* test)
{

	UE_LOG(LogTemp, Warning, TEXT("Actor Death!"));

	if (test != nullptr)
	{
		test->Destroy();
	}

	//UE_LOG(LogTemp, Warning, TEXT("REducing lives... %i"), PlayerState->Lives);
}

void AGameModeF::CheckEnemiesKilled()
{
	enemiesLeft--;

	if (enemiesLeft <= 0)
	{
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

void AGameModeF::Respawn(APlayerController* player)
{
	UE_LOG(LogTemp, Warning, TEXT("Respawn...."));

	if (player) 
	{
		RestartPlayer(player);
	}
}