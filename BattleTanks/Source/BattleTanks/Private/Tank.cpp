// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank.h"
#include "BattleTanks.h"
#include "Public/TankAimingComponent.h"
#include "Public/Projectile.h"
#include "Engine/World.h"
#include "Public/TankBarrel.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//no need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;

}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);

}
// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector OutHitLocation)
{
	TankAimingComponent->AimAt(OutHitLocation, ProjectileSpeed);
	
}

void ATank::Fire()
{
	if (!Barrel) { return; }

	

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
	);

	Projectile->LaunchProjectile(ProjectileSpeed);

	
}