// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector OutHitLocation, float ProjectileSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	const FCollisionResponseParams ResponseParam;
	const TArray <AActor * > ActorsToIgnore;


	

	
	// Calculates  correct Launch velocity in order to hit the end point location with projectile speed
	if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			OutLaunchVelocity,
			StartLocation,
			OutHitLocation,
			ProjectileSpeed,
			ESuggestProjVelocityTraceOption::DoNotTrace
			)	
		)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		FString newstring = FString::SanitizeFloat(ProjectileSpeed);
		auto OutTankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s"), *OutTankName, *AimDirection.ToString())
	}
	
	
	/*;
	auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	
	UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s from %s"), *OutTankName, *OutHitLocation.ToString(), *BarrelLocation)*/
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	 //Need to get the correct rotation for the barrel (AimDirectionMaybe?)
	auto BarrelRotator = Barrel->GetForwardVector().Rotation;

	auto AimAsRotator = AimDirection.Rotation();

	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString());
	//point barrel 

	//recalculate this over and over??*/

}



