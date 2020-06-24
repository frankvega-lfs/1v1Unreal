// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100;
	Health = MaxHealth;


	// ...
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void UHealthComponent::ApplyDamage(float Damage, const AActor* DamageCauser)
{
	Health -= Damage;

	OnDamageReceived.Broadcast(DamageCauser);

	if (Health <= 0)
	{
		Health = 0;
		OnDead.Broadcast();
	}

	//UE_LOG(LogTemp, Warning, TEXT("Damage applied, current health is : %i"), Health);

	UE_LOG(LogTemp, Warning, TEXT("Health : %i"), Health);

}

