// Copyright Dead Weight Dave Inc 2017

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class TankAimingComponent;

/**
 * the Tanks AI Controller
 */
UCLASS()
class TOUGHTANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	void BeginPlay();
protected:
	UPROPERTY(EditAnywhere, Category = "Setup")// consider EditDefaultsOnly
		float AcceptanceRadis = 80;// how close the AI can Get to the player
private:
	//	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

};

