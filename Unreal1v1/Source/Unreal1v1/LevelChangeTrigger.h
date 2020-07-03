// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelChangeTrigger.generated.h"

UCLASS()
class UNREAL1V1_API ALevelChangeTrigger : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* TriggerVolume;

protected:
	UPROPERTY(EditAnywhere)
		FString MapName;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

public:	
	// Sets default values for this actor's properties
	ALevelChangeTrigger();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void OnTriggerOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
