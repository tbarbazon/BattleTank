// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "Public/Tank.h"
#include "Engine/World.h"

#include "TankPlayerController.generated.h" //must be last include

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	// start tank moving barrel so that a shot would hit where
	// the crosshair intersects the world
	

private:
	
	ATank* GetControlledTank() const;
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
	void AimTowardsCrossHair();

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.5;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
