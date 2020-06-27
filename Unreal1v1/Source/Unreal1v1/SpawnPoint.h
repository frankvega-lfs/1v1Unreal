// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnPoint.generated.h"

UCLASS()
class UNREAL1V1_API ASpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPoint();

	UPROPERTY(EditDefaultsOnly, Category = Enemy)
	TSubclassOf<class ABasicController> EnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float SpawnRateTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float SpawnRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnSpawn();

};
