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
//	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	//	FVector RockForce =  (0.f,100.f,0.f);
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 45;


};
