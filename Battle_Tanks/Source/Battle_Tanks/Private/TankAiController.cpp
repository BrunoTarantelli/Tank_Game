// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAiController.h"
#include "..\Public\TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

	auto PlayerTank = GetPlayerTank();

}

void  ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}


ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}

	return Cast<ATank>(PlayerPawn);
}