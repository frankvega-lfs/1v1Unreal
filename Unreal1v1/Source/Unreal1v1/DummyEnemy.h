// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Damageable.h"
#include "Interactable.h"
#include "DummyEnemy.generated.h"

class UHealthComponent;

UCLASS()
class UNREAL1V1_API ADummyEnemy : public AActor, public IDamageable, public IInteractable
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		class USceneComponent* RootComp;

		UPROPERTY(EditAnywhere)
		UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* DamageVolume;

	UPROPERTY(EditAnywhere)
		bool IsInteractable;
	
public:	
	// Sets default values for this actor's properties
	ADummyEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnDamageReceived(const AActor* DamageCauser);

	UFUNCTION()
		virtual void OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual UHealthComponent* GetHealthComponent() const override { return HealthComponent; }

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	virtual bool CanInteract() const override;
};
