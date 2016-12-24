// Copyright Dead Weight Dave Inc 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOUGHTANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Azimuth(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 25;

};
