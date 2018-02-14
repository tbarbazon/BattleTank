// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
public:
	void virtual BeginPlay() override;
	void virtual Tick(float deltatime) override;

private:
	ATank* GetPossesedTank() const;
	
	ATank* GetPlayerTank() const;


	
};
