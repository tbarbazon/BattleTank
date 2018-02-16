// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankBarrel.h"



void UTankBarrel::Elevate(float DegreesPerSecond)
{
	FString DPSstring = FString::SanitizeFloat(DegreesPerSecond);
	UE_LOG(LogTemp,Warning,TEXT(" DegreesPerSecond: %s"), *DPSstring)
}


