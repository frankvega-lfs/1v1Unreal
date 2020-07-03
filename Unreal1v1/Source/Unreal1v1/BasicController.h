// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Damageable.h"
#include "Interactable.h"
#include "BasicController.generated.h"

class UHealthComponent;

UCLASS(config=Game)
class ABasicController : public ACharacter, public IDamageable
{
	GENERATED_BODY()		

	UPROPERTY(EditAnywhere)
		UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere)
		float DamageValue;

	UPROPERTY(EditAnywhere)
		float DamageInterval = 1.5f;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* DamageVolume;

	UPROPERTY()
		TArray<AActor*> ActorsToDamage;

	FTimerHandle DamageTimerHandle;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void DamageTick();


public:
	ABasicController();

	//FTimerHandle DestroyHandle;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	virtual UHealthComponent* GetHealthComponent() const override { return HealthComponent; }

	/*UFUNCTION()
		void OnDamageReceived(const AActor* DamageCauser);*/

	UFUNCTION()
		void OnDead();

	UFUNCTION()
		virtual void OnCharacterVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnDamageVolumeOverlappedEnd(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

