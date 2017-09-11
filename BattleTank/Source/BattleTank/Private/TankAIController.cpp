// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)// Tick
{
	Super::Tick(DeltaSeconds);// Super

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank))
	{
		//Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is centimeter

		// Aim towards the player
		auto AimimgComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimimgComponent->AimAt(PlayerTank->GetActorLocation());

		// TODO Fix firing
		//ControlledTank->Fire();
		
	}
}


