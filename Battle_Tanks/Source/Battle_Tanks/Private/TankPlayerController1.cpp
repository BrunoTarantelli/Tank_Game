// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tanks.h"
#include "TankPlayerController1.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

