// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BluePrintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; //sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 45; // default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0; //default

	
	
	
	
};
