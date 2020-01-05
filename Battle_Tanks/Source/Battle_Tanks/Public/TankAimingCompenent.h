// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Quat.h"
#include "Components/ActorComponent.h"
#include "TankAimingCompenent.generated.h"

//Enums
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

//foward declaration
class UTankBarrel;
class UTankTurret;

//Contem parametros do cano e metodo Elevate
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANKS_API UTankAimingCompenent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;

private:
	// Sets default values for this component's properties
	UTankAimingCompenent();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
