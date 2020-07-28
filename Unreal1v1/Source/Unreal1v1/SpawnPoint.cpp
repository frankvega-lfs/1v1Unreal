// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPoint.h"
#include "BasicCharacter.h"
#include "TimerManager.h"
#include "Engine/World.h"
// Sets default values
ASpawnPoint::ASpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(SpawnHandle, this, &ThisClass::Spawn, SpawnRate, true);
}

void ASpawnPoint::Spawn()
{
	SpawnLimit--;
	if (SpawnLimit>=0)
	{
		UWorld* const World = GetWorld();

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.Owner = this;

		const FRotator SpawnRotation = this->GetActorRotation();
		const FVector SpawnLocation = this->GetActorLocation();
		World->SpawnActor<ABasicCharacter>(EnemyClass, SpawnLocation, SpawnRotation);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(SpawnHandle);
	}
	
}

// Called every frame
void ASpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


