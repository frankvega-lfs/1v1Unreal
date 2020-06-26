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

		/*UPROPERTY(EditAnywhere)
		class USceneComponent* RootComp;*/

	UPROPERTY(EditAnywhere)
		UHealthComponent* HealthComponent;

	/*UPROPERTY(EditAnywhere)
		class UCapsuleComponent* DamageVolume;*/


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	ABasicController();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnDamageReceived(const AActor* DamageCauser);

	UFUNCTION()
		void OnDead();

	UFUNCTION()
		virtual void OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual UHealthComponent* GetHealthComponent() const override { return HealthComponent; }

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

};

