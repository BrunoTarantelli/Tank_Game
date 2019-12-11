// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tanks.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController1.h"
#include "..\Public\TankPlayerController1.h"

void ATankPlayerController1::BeginPlay()
{
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();

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
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation; // Parametro OUT
	if (GetSightRayHitLocation(HitLocation)) //fara um line trace
	{
		GetControlledTank()->AimAt(HitLocation);
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
	return true;
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


