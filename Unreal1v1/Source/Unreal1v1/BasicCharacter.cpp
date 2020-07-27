// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BasicCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameModeF.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "HealthComponent.h"
#include "TimerManager.h"
#include "FPSCharacter.h"
#include "FPSTestProjectile.h"

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

}

<<<<<<< HEAD:Unreal1v1/Source/Unreal1v1/BasicCharacter.cpp
/*void ABasicCharacter::OnDamageReceived(const AActor* DamageCauser)
{
	//TODO APPLY DAMAGE
}*/

void ABasicCharacter::OnDead()
=======
// Called every frame
void ABasicController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicController::OnDead()
>>>>>>> 888cb2d02ba5fc7dce73d6953e8ff37e75ba6373:Unreal1v1/Source/Unreal1v1/BasicController.cpp
{
	AGameModeF* GameMode = GetWorld()->GetAuthGameMode<AGameModeF>();
	GetController()->UnPossess();

	DamageVolume->DestroyComponent();
	GetCapsuleComponent()->DestroyComponent();
	GetCharacterMovement()->DisableMovement();
	GameMode->CheckEnemiesKilled();

	//Ragdoll Mode (It crashes at random times at the moment)
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetAllBodiesSimulatePhysics(true);
<<<<<<< HEAD:Unreal1v1/Source/Unreal1v1/BasicCharacter.cpp
	GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &ABasicCharacter::CallDestroy, 3.0f, false);
}

void ABasicCharacter::CallDestroy()
=======
	GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &ABasicController::CallDestroy, 3.0f, false);
}


void ABasicController::CallDestroy()
{
	Destroy();
}




void ABasicController::OnCharacterVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
>>>>>>> 888cb2d02ba5fc7dce73d6953e8ff37e75ba6373:Unreal1v1/Source/Unreal1v1/BasicController.cpp
{
	Destroy();
}

void ABasicCharacter::OnDamageVolumeOverlapped(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Other == nullptr)
		return;

	GetWorld()->GetTimerManager().SetTimer(DamageTimerHandle, this, &ThisClass::DamageTick, DamageInterval, true);

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

<<<<<<< HEAD:Unreal1v1/Source/Unreal1v1/BasicCharacter.cpp
=======
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

>>>>>>> 888cb2d02ba5fc7dce73d6953e8ff37e75ba6373:Unreal1v1/Source/Unreal1v1/BasicController.cpp
	if (HealthComponent->OnDead.IsAlreadyBound(this, &ThisClass::OnDead))
	{
		HealthComponent->OnDead.RemoveDynamic(this, &ThisClass::OnDead);
	}

}