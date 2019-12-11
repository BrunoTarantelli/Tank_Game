// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSeconds = 20; ///padrao medio

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 30; ///padrao medio

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0; ///padrao medio
};
