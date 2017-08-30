// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/TankAIController.h"
#include "../Public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is not found player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()))
	}
}

void ATankAIController::Tick(float DeltaSeconds)// Tick
{
	Super::Tick(DeltaSeconds);// Super
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire it ready
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

ATank* ATankAIController::GetAIControlledTank() const {
	return Cast<ATank>(GetPawn());
}


