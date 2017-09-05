// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/TankAIController.h"
#include "Engine/World.h"
#include "../Public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)// Tick
{
	Super::Tick(DeltaSeconds);// Super
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// TODO Move towards the player

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire it ready
		ControlledTank->Fire(); //TODO limit firing rate
		
	}
}


