// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Interfaces/HealthComponent.h"
#include "Weapons/PlayerGun.h"
#include "GameFrameworkClasses/GameModeF.h"
#include "Interfaces/Interactable.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;

	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	FP_Gun->SetupAttachment(Mesh1P, TEXT("R_GunSocket"));

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);

	PlayerGun = CreateDefaultSubobject<UPlayerGun>(TEXT("Weapon Logic"));
	//PlayerGun->Set(GetCapsuleComponent());
	PlayerGun->FP_MuzzleLocation = FP_MuzzleLocation;
	PlayerGun->Mesh1P = Mesh1P;
	PlayerGun->FireAnimation = FireAnimation;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent2"));
	UE_LOG(LogTemp, Warning, TEXT("Health created"));
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerGun->FireAnimation = FireAnimation;
	OriginalWalkSpeed = WalkSpeed;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	//HealthComponent->OnDamageReceived.AddDynamic(this, &ThisClass::OnDamageReceived);
	HealthComponent->OnDead.AddDynamic(this, &ThisClass::Die);
}

void AFPSCharacter::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (HealthComponent->OnDead.IsAlreadyBound(this, &ThisClass::Die))
	{
		HealthComponent->OnDead.RemoveDynamic(this, &ThisClass::Die);
	}
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::FireGun);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AFPSCharacter::StopFireGun);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFPSCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFPSCharacter::StopSprint);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::Jump);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFPSCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFPSCharacter::LookUpAtRate);
	
}

void AFPSCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
		bIsMovingForward = true;
	}
	else
	{
		bIsMovingForward = false;
	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
		bIsMovingRight = true;
	}
	else
	{
		bIsMovingRight = false;
	}
}

void AFPSCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFPSCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AFPSCharacter::FireGun()
{
	if (PlayerGun != NULL)
	{
		PlayerGun->OnFire();
	}
}

void AFPSCharacter::StopFireGun()
{
	if (PlayerGun != NULL)
	{
		PlayerGun->OnStopFire();
	}
}

void AFPSCharacter::Sprint()
{
	WalkSpeed = OriginalWalkSpeed * SprintMultiplier;

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	bIsSprinting = true;
}

void AFPSCharacter::StopSprint()
{
	WalkSpeed = OriginalWalkSpeed;

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	bIsSprinting = false;
}

/*void AFPSCharacter::OnDamageReceived(const AActor* DamageCauser)
{
	//TODO Damage Logic
}*/

void AFPSCharacter::Die()
{
	this->GetCharacterMovement()->DisableMovement();
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	this->DisableInput(PlayerController);

	if (PlayerGun != NULL)
	{
		PlayerGun->OnStopFire();
	}

	AGameModeF* GameMode = GetWorld()->GetAuthGameMode<AGameModeF>();
	GameMode->ReduceLives(this);
}


