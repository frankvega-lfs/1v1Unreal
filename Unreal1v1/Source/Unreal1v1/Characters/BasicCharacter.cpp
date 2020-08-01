// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BasicCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFrameworkClasses/GameModeF.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Interfaces/HealthComponent.h"
#include "TimerManager.h"
#include "FPSCharacter.h"
#include "Weapons/FPSTestProjectile.h"
#include "Kismet/GameplayStatics.h"

//////////////////////////////////////////////////////////////////////////
// AImageCampusProjectCharacter

ABasicCharacter::ABasicCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	DamageVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Damage Volume"));
	DamageVolume->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	DamageVolume->SetupAttachment(RootComponent);
	GetCapsuleComponent()->SetupAttachment(RootComponent);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();

	DamageVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	DamageVolume->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageVolumeOverlappedEnd);
	//HealthComponent->OnDamageReceived.AddDynamic(this, &ThisClass::OnDamageReceived);
	HealthComponent->OnDead.AddDynamic(this, &ThisClass::OnDead);
	HealthComponent->OnHurt.AddDynamic(this, &ThisClass::OnHurt);
}


/*void ABasicCharacter::OnDamageReceived(const AActor* DamageCauser)
{
	//TODO APPLY DAMAGE
}*/


// Called every frame
void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicCharacter::OnHurt()
{
	if (HealthComponent->GetCurrentHealth() > 0)
	{
		// try and play the sound if specified
		if (HurtSound != NULL)
		{
			USoundConcurrency* ConcurrencySettings = (USoundConcurrency*)nullptr;

			UGameplayStatics::PlaySoundAtLocation
			(
				this,
				HurtSound,
				GetActorLocation(),
				1.0f,
				1.0f,
				0.0f,
				Attenuation,
				ConcurrencySettings
			);

			//UGameplayStatics::PlaySoundAtLocation(this, HurtSound, GetActorLocation(), Attenuation);
		}
	}
}

void ABasicCharacter::OnDead()
{
	// try and play the sound if specified
	if (DeathSound != NULL)
	{
		USoundConcurrency* ConcurrencySettings2 = (USoundConcurrency*)nullptr;

		UGameplayStatics::PlaySoundAtLocation
		(
			this,
			DeathSound,
			GetActorLocation(),
			1.0f,
			1.0f,
			0.0f,
			Attenuation,
			ConcurrencySettings2
		);

		//UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation(), Attenuation);
	}

	AGameModeF* GameMode = GetWorld()->GetAuthGameMode<AGameModeF>();
	GetController()->UnPossess();

	DamageVolume->DestroyComponent();
	GetCapsuleComponent()->DestroyComponent();
	GetCharacterMovement()->DisableMovement();
	GameMode->CheckEnemiesKilled();

	//Ragdoll Mode
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetAllBodiesSimulatePhysics(true);
	GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &ABasicCharacter::CallDestroy, 3.0f, false);
}

void ABasicCharacter::CallDestroy()
{
	Destroy();
}


void ABasicCharacter::OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Other == nullptr)
		return;

	GetWorld()->GetTimerManager().SetTimer(DamageTimerHandle, this, &ThisClass::DamageTick, DamageInterval, true);

	ABasicCharacter* Character = Cast<ABasicCharacter>(Other->GetOwner());

	if (Character != nullptr)
		return;

	IDamageable* Damageable = Cast<IDamageable>(Other);

	if (Damageable == nullptr)
		return;

	ActorsToDamage.Add(Other);

	UE_LOG(LogTemp, Warning, TEXT(" OnDamageVolumeOverlapped - Other Actor Name: %s"), *Other->GetName());

}

void ABasicCharacter::OnDamageVolumeOverlappedEnd(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Other == nullptr)
		return;

	ABasicCharacter* Character = Cast<ABasicCharacter>(Other->GetOwner());

	if (Character != nullptr)
		return;

	ActorsToDamage.Remove(Other);

	if (ActorsToDamage.Num() <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(DamageTimerHandle);
	}

	UE_LOG(LogTemp, Warning, TEXT("OnDamageVolumeOverlapeedEnd - Other Actor Name: %s"), *Other->GetName());

}

void ABasicCharacter::DamageTick()
{
	for (AActor* Actor : ActorsToDamage)
	{
		if (Actor != nullptr)
		{
			AFPSCharacter* Character = Cast<AFPSCharacter>(Actor);

			if (Character != nullptr)
			{
				IDamageable* Damageable = Cast<IDamageable>(Character);

				if (Damageable != nullptr)
				{
					Damageable->OnTakeDamage(DamageValue, this);

					UE_LOG(LogTemp, Warning, TEXT("Damage Tick"));
				}
			}
			

		}

	}
}

void ABasicCharacter::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	//if (GetCapsuleComponent()->OnComponentBeginOverlap.IsAlreadyBound(this, &ThisClass::OnCharacterVolumeOverlapped))
	//{
	//	GetCapsuleComponent()->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnCharacterVolumeOverlapped);
	//}

	//if (DamageVolume->OnComponentBeginOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlapped))
	//{
	//	DamageVolume->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlapped);
	//}

	//if (DamageVolume->OnComponentEndOverlap.IsAlreadyBound(this, &ThisClass::OnDamageVolumeOverlappedEnd))
	//{
	//	DamageVolume->OnComponentEndOverlap.RemoveDynamic(this, &ThisClass::OnDamageVolumeOverlappedEnd);
	//}

	/*if (HealthComponent->OnDamageReceived.IsAlreadyBound(this, &ThisClass::OnDamageReceived))
	{
		HealthComponent->OnDamageReceived.RemoveDynamic(this, &ThisClass::OnDamageReceived);
	}*/

	if (HealthComponent->OnHurt.IsAlreadyBound(this, &ThisClass::OnHurt))
	{
		HealthComponent->OnHurt.RemoveDynamic(this, &ThisClass::OnHurt);
	}

	if (HealthComponent->OnDead.IsAlreadyBound(this, &ThisClass::OnDead))
	{
		HealthComponent->OnDead.RemoveDynamic(this, &ThisClass::OnDead);
	}

	

}