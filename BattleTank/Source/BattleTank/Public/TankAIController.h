// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 8000;

private:
	virtual void Tick(float DeltaSeconds);

	virtual void SetPawn(APawn* InPawn) override;

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTankDeath();

};
