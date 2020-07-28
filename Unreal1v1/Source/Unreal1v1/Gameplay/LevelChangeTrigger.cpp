// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelChangeTrigger.h"
#include "Components/BoxComponent.h"
#include "Characters/FPSCharacter.h"
#include "GameFrameworkClasses/GameModeF.h"

// Sets default values
ALevelChangeTrigger::ALevelChangeTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	TriggerVolume->SetupAttachment(RootComp);

}

// Called when the game starts or when spawned
void ALevelChangeTrigger::BeginPlay()
{
	Super::BeginPlay();

	TriggerVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnTriggerOverlapped);
	
}

void ALevelChangeTrigger::EndPlay(EEndPlayReason::Type EndPlayReason)
{

	if (TriggerVolume->OnComponentBeginOverlap.IsAlreadyBound(this, &ThisClass::OnTriggerOverlapped))
	{
		TriggerVolume->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnTriggerOverlapped);
	}
}

// Called every frame
void ALevelChangeTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelChangeTrigger::OnTriggerOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Other == nullptr)
		return;

	AFPSCharacter* Character = Cast<AFPSCharacter>(Other);

	if (Character != nullptr)
	{
		// Call Gamemode to change level 
	// game mode searches level name from its array
	// if it finds the name it changes to it.

		AGameModeF* GameMode = GetWorld()->GetAuthGameMode<AGameModeF>();
		GameMode->ChangeMap(MapName);
	}
}

