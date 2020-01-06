// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "TankAimingCompenent.h"
#include "..\Public\TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
}

void  ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank) && ControlledTank) { return; }

	MoveToActor(PlayerTank, AccptanceRadius);
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingCompenent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//ControlledTank->Fire();
	
}
