// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h"

//Forward Declarations
class UTankBarrel; 
class UTankAimingComponent;
class UTankTurret;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

	

protected:
	
	UTankAimingComponent* TankAimingComponent = nullptr;

public:	

	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void Fire();

	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	UPROPERTY(EditAnywhere, Category = Firing)
		float ProjectileSpeed = 10000; //TODO find sensible default
	
private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Sets default values for this pawn's properties
	ATank();
	
	
};
