// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "GameModeF.h"
#include "Components/CapsuleComponent.h"
#include "HealthComponent.h"
#include "Damageable.h"
#include "FPSTestProjectile.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	DamageVolume = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Damage Volume"));
	DamageVolume->SetupAttachment(RootComp);
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent2"));

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	DamageVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	HealthComponent->OnDamageReceived.AddDynamic(this, &ThisClass::OnDamageReceived);

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::OnDamageReceived(const AActor* DamageCauser)
{
	if (HealthComponent->Health <= 0)
	{
		AGameModeF* GameMode = GetWorld()->GetAuthGameMode<AGameModeF>();
		GameMode->ReduceLives(this);

		//UE_LOG(LogTemp, Warning, TEXT("OnDamageVolumeOverlapeedEnd - Other Actor Name: %s"), *Other->GetName());

		HealthComponent->Health = 0;
	}
}

void AEnemy::OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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

void AEnemy::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (DamageVolume->OnComponentBeginOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlapped))
	{
		DamageVolume->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	}
}

