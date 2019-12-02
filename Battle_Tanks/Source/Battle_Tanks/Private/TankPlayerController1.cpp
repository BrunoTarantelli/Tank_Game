// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tanks.h"
#include "TankPlayerController1.h"
#include "..\Public\TankPlayerController1.h"

void ATankPlayerController1::BeginPlay()
{
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();

	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController não possui um tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possui o tank: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController1::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController1::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;}
	else
	{
		//GetWorldLocation se LineTrace pela reticula
	}
}