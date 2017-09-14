// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h" // So we can implement OnDeath

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::OnTankDeath()
{
	if (!ensure(GetPawn())) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}

void ATankAIController::Tick(float DeltaSeconds)// Tick
{
	Super::Tick(DeltaSeconds);// Super

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is centimeter

	// Aim towards the player
	auto AimimgComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimimgComponent->AimAt(PlayerTank->GetActorLocation());

	// if aim or locked
	if (AimimgComponent->GetFiringState() == EFiringState::Locked)
	{
		AimimgComponent->Fire();
	}
}




