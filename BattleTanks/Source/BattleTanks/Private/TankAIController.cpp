// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PossesedTank = GetPossesedTank();
	if (!PossesedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAI Controller Not Possesing Tank"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("%s under control"), *(PossesedTank->GetName()));
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAI Controller Could not find TankPlayerController"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s found as human. Commencing Attack!"), *(PlayerTank->GetName()));
	}
	


}

ATank* ATankAIController::GetPlayerTank() const
{
	auto controller = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(controller);
}
ATank* ATankAIController::GetPossesedTank() const
{
	return Cast<ATank>(GetPawn());
}

