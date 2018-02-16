// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Public/CollisionQueryParams.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Math/Vector.h"


#include "TankAimingComponent.generated.h"
//Forward Declaration
class UTankBarrel; 

// Holds Barrels Properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

	

protected:


public:	

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	
	// Sets default values for this component's properties
	UTankAimingComponent();
	

	void AimAt(FVector OutHitLocation, float ProjectileSpeed);

private:

	UTankBarrel * Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	
	
};
