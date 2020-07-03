// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateFPS.h"

APlayerStateFPS::APlayerStateFPS()
{
	MaxLives = 3;
	Lives = MaxLives;
}

void APlayerStateFPS::Kill()
{
	Lives -= 1;


	if (Lives < 0)
	{
		Lives = 0;
	}
}

void APlayerStateFPS::SetMaxLives(int amount)
{
	MaxLives = amount;
	Lives = MaxLives;
}
