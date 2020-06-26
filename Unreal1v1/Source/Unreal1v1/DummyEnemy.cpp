// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyEnemy.h"
#include "GameModeF.h"
#include "Components/CapsuleComponent.h"
#include "HealthComponent.h"
#include "Damageable.h"
#include "FPSTestProjectile.h"

// Sets default values
ADummyEnemy::ADummyEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	DamageVolume = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Damage Volume"));
	DamageVolume->SetupAttachment(RootComp);
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent2"));
	//IsInteractable = true;
}

// Called when the game starts or when spawned
void ADummyEnemy::BeginPlay()
{
	Super::BeginPlay();

	DamageVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	HealthComponent->OnDamageReceived.AddDynamic(this, &ThisClass::OnDamageReceived);
	HealthComponent->OnDead.AddDynamic(this, &ThisClass::OnDead);
	//DamageVolume->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlappedEnd);
	
}

// Called every frame
void ADummyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADummyEnemy::OnDamageReceived(const AActor* DamageCauser)
{
	//TODO APPLY DAMAGE
}

void ADummyEnemy::OnDead()
{

	AGameModeF* GameMode = GetWorld()->GetAuthGameMode<AGameModeF>();
	GameMode->ReduceLives(this);

	//UE_LOG(LogTemp, Warning, TEXT("OnDamageVolumeOverlapeedEnd - Other Actor Name: %s"), *Other->GetName());

}

void ADummyEnemy::OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Other == nullptr)
		return;

	AFPSTestProjectile* Projectile = Cast<AFPSTestProjectile>(Other);

	if (Projectile == nullptr)
		return;

	Projectile->Destroy();

	OnTakeDamage(10, this);

	UE_LOG(LogTemp, Warning, TEXT(" OnDamageVolumeOverlapped - Other Actor Name: %s"), *Other->GetName());

}

void ADummyEnemy::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (DamageVolume->OnComponentBeginOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlapped))
	{
		DamageVolume->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	}

	if (HealthComponent->OnDamageReceived.IsAlreadyBound(this, &ThisClass::OnDamageReceived))
	{
		HealthComponent->OnDamageReceived.RemoveDynamic(this, &ThisClass::OnDamageReceived);
	}

	if (HealthComponent->OnDead.IsAlreadyBound(this, &ThisClass::OnDead))
	{
		HealthComponent->OnDead.RemoveDynamic(this, &ThisClass::OnDead);
	}

	//HealthComponent->OnDamageReceived.AddDynamic(this, &ThisClass::OnDamageReceived);
	//HealthComponent->OnDead.AddDynamic(this, &ThisClass::OnDead);

	/*if (DamageVolume->OnComponentEndOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlappedEnd))
	{
		DamageVolume->OnComponentEndOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlappedEnd);
	}*/


}

bool ADummyEnemy::CanInteract() const
{
	return IsInteractable;
}

