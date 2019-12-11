// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tanks.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "..\Public\TankAimingCompenent.h"

// Sets default values for this component's properties
UTankAimingCompenent::UTankAimingCompenent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingCompenent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingCompenent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}


// Called when the game starts
void UTankAimingCompenent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UTankAimingCompenent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingCompenent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }//protrecao
	
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveAimSolution)//se calcular OutLaunchVelocity
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingCompenent::MoveBarrelTowards(FVector AimDirection) //alinhar cano com reticula de mira
{
	auto BarrelRotator= Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

