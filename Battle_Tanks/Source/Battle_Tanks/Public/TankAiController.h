// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

UCLASS()
class BATTLE_TANKS_API ATankAiController : public AAIController
{
	GENERATED_BODY()

protected:

	//Quao perto do jogador a IA chega
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AccptanceRadius = 8000;

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
