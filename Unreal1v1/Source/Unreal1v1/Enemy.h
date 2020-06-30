// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Damageable.h"
#include "Interactable.h"
#include "Enemy.generated.h"

UCLASS()
class UNREAL1V1_API AEnemy : public ACharacter, public IDamageable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();


protected:
	// Called when the game starts or when spawned

	UPROPERTY(EditAnywhere)
		class USceneComponent* RootComp;

	UPROPERTY(EditAnywhere)
		UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* DamageVolume;

	UPROPERTY(EditAnywhere)
		float Damage;

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void OnDamageReceived(const AActor* DamageCauser);

	UFUNCTION()
		void OnDead();

	UFUNCTION()
		virtual void OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	FTimerHandle DestroyHandle;
	void CallDestroy();

	virtual UHealthComponent* GetHealthComponent() const override { return HealthComponent; }

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

};
