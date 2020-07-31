// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageReceived, const AActor*, DamageCauser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHurt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDead);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL1V1_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	virtual void ApplyDamage(float Damage, const AActor* DamageCauser);

	UPROPERTY(BlueprintAssignable)
		FOnDamageReceived OnDamageReceived;

	UPROPERTY(BlueprintAssignable)
		FOnDead OnDead;

	UPROPERTY(BlueprintAssignable)
		FOnDead OnHurt;

	UFUNCTION()
		float GetCurrentHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		int MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Health;
};
