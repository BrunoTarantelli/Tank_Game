// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tanks.h"
#include "TankAimingCompenent.h"
#include "Engine/World.h"
#include "TankPlayerController1.h"
#include "..\Public\TankPlayerController1.h"

void ATankPlayerController1::BeginPlay()
{
	Super::BeginPlay();
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingCompenent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController1::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingCompenent>();
	if (!ensure(AimingComponent)) { return; }
	
	FVector HitLocation; // Parametro OUT
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	
	if (bGotHitLocation) //fara um line trace
	{
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController1::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Acha reticula em coordenada de pixels
	int32 ViewportSizeX, ViewportSizeY; 
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	//De-project
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return false;
}

bool ATankPlayerController1::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // necessario mas descartado
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController1::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceEnd);

	if (GetWorld()->LineTraceSingleByChannel(
			HitResult, StartLocation, EndLocation,ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}


