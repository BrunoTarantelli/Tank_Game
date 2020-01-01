// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAiController.h"
#include "..\Public\TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
}

void  ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AccptanceRadius);

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();
	}
}
