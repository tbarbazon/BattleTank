// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Battletanks.h"

//tick
	//super tick
	



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled Not Possesing Tank"));
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlling %s"), *(ControlledTank->GetName()));
	}
}	

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
	UE_LOG(LogTemp, Warning, TEXT("Tick Ticking"));
}
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair() 
{
	if (!GetControlledTank()) { return; }

	//get world location through crosshair
	//if it hits something tell controlled tank to aim at this point

}
