// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BasicController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameModeF.h"
#include "Components/CapsuleComponent.h"
#include "HealthComponent.h"
#include "Damageable.h"
#include "FPSTestProjectile.h"

//////////////////////////////////////////////////////////////////////////
// AImageCampusProjectCharacter

ABasicController::ABasicController()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	//DamageVolume = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Damage Volume"));
	//DamageVolume->SetupAttachment(RootComp);
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

// Called when the game starts or when spawned
void ABasicController::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	HealthComponent->OnDamageReceived.AddDynamic(this, &ThisClass::OnDamageReceived);
	HealthComponent->OnDead.AddDynamic(this, &ThisClass::OnDead);
	//DamageVolume->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlappedEnd);

}

// Called every frame
void ABasicController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicController::OnDamageReceived(const AActor* DamageCauser)
{
	//TODO APPLY DAMAGE
}

void ABasicController::OnDead()
{

	AGameModeF* GameMode = GetWorld()->GetAuthGameMode<AGameModeF>();
	GameMode->ReduceLives(this);

	//UE_LOG(LogTemp, Warning, TEXT("OnDamageVolumeOverlapeedEnd - Other Actor Name: %s"), *Other->GetName());

}

void ABasicController::OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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

void ABasicController::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GetCapsuleComponent()->OnComponentBeginOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlapped))
	{
		GetCapsuleComponent()->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	}

	if (HealthComponent->OnDamageReceived.IsAlreadyBound(this, &ThisClass::OnDamageReceived))
	{
		HealthComponent->OnDamageReceived.RemoveDynamic(this, &ThisClass::OnDamageReceived);
	}

	if (HealthComponent->OnDead.IsAlreadyBound(this, &ThisClass::OnDead))
	{
		HealthComponent->OnDead.RemoveDynamic(this, &ThisClass::OnDead);
	}

}