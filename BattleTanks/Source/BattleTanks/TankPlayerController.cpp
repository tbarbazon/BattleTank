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
	//UE_LOG(LogTemp, Warning, TEXT("Tick Ticking"));
}
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair() 
{
	if (!GetControlledTank()) { return; }
	
	FVector OutHitLocation; //outParam
	if (GetSightRayHitLocation(OutHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *OutHitLocation.ToString());

		//TODO tell tank to aim 
		//TODO Probably will comment this out

	}

	
	
	

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// find corsshair possition
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	

	//de-project screen position to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//line trace along direction
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	
	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	auto StartLocation = PlayerCameraManager->GetCameraLocation(); 
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	FHitResult OutHit;
	if (GetWorld()->LineTraceSingleByChannel(
			OutHit, 
			StartLocation, 
			EndLocation, 
			ECollisionChannel::ECC_Visibility)
		)
	{
		OutHitLocation = OutHit.Location;
		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("Nothing Found"))
	return false;
}