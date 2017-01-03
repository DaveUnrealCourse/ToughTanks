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
	UFUNCTION(BlueprintCallable, Category = "Input")
		void RockLeft();
	UFUNCTION(BlueprintCallable, Category = "Input")
		void RockRight();
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 25;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float RockForce = 25000;

};
