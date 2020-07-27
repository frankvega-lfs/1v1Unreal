// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "Damageable.h"
#include "Interactable.h"
#include "BasicCharacter.generated.h"

class UHealthComponent;

UCLASS(config=Game)
class ABasicCharacter : public ACharacter, public IDamageable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	class USceneComponent* RootComp;

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

	UPROPERTY()
<<<<<<< HEAD:Unreal1v1/Source/Unreal1v1/BasicCharacter.h
		FTimerHandle DamageTimerHandle;

	UFUNCTION()
		void CallDestroy();
=======
	FTimerHandle DamageTimerHandle;
>>>>>>> 888cb2d02ba5fc7dce73d6953e8ff37e75ba6373:Unreal1v1/Source/Unreal1v1/BasicController.h

	UFUNCTION()
		void CallDestroy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void DamageTick();


public:
	ABasicCharacter();

<<<<<<< HEAD:Unreal1v1/Source/Unreal1v1/BasicCharacter.h
	//FTimerHandle DestroyHandle;
=======
	// Called every frame
	virtual void Tick(float DeltaTime) override;
>>>>>>> 888cb2d02ba5fc7dce73d6953e8ff37e75ba6373:Unreal1v1/Source/Unreal1v1/BasicController.h

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	virtual UHealthComponent* GetHealthComponent() const override { return HealthComponent; }

	/*UFUNCTION()
		void OnDamageReceived(const AActor* DamageCauser);*/

	UFUNCTION()
		void OnDead();

	UFUNCTION()
		virtual void OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnDamageVolumeOverlappedEnd(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

