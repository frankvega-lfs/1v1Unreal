// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Damageable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UDamageable : public UInterface
{
	GENERATED_BODY()
};

class UNREAL1V1_API IDamageable
{
	GENERATED_BODY()
	
public:

	virtual class UHealthComponent* GetHealthComponent() const = 0;
	virtual void OnTakeDamage(float Damage, const AActor* DamageCauser);
};
