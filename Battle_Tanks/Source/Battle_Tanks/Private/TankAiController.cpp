// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "..\Public\TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController não achou o PC"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController achou o: %s"), *(PlayerTank->GetName()));
	}
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