// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL1V1_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(Transient)
		TArray<class UButton*> Buttons;

	UPROPERTY(meta = (BindWidget))
		class UVerticalBox* VBoxButtons;

	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void OnButtonClicked();
	
};
