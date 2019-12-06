// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingCompenent.h"
#include "..\Public\TankAimingCompenent.h"

// Sets default values for this component's properties
UTankAimingCompenent::UTankAimingCompenent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingCompenent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
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

void UTankAimingCompenent::AimAt(FVector HitLocation)
{
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation =Barrel->GetComponentLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s mirando em %s do local %s"), *OurTankName, *HitLocation.ToString(), *BarrelLocation);
}

