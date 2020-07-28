// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Damageable.h"
#include "FPSCharacter.generated.h"

class UHealthComponent;
class UPlayerGun;

UCLASS()
class AFPSCharacter : public ACharacter, public IDamageable
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
		float SprintMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Player)
		float WalkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player)
		float OriginalWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gun)
	UPlayerGun* PlayerGun;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_Gun;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(EditAnywhere, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UHealthComponent* HealthComponent;


public:	
	// Sets default values for this character's properties
	AFPSCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual UHealthComponent* GetHealthComponent() const override { return HealthComponent; }

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveRight(float Value);

	UFUNCTION()
		void MoveForward(float Value);

	UFUNCTION()
		void TurnAtRate(float Rate);

	UFUNCTION()
		void LookUpAtRate(float Rate);

	UFUNCTION()
		void FireGun();

	UFUNCTION()
		void StopFireGun();

	UFUNCTION()
		void Sprint();

	UFUNCTION()
		void StopSprint();

	/*UFUNCTION()
		void OnDamageReceived(const AActor* DamageCauser);*/

	UFUNCTION()
		void Die();

	UFUNCTION(BlueprintCallable)
		void TestDamage(int _damage)
		{
			OnTakeDamage(_damage, nullptr);
		}

	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	
};
