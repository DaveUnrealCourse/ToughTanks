// Copyright Dead Weight Dave Inc 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "BarrelSec.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOUGHTANKS_API UBarrelSec : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is Max Downward Speed And +1 is max up Movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 10;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxElevationDegrees = 40;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MinElevationDegrees = -2;

};