// Copyright Dead Weight Dave Inc 2017

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// must be the last 

/**
 * the controller for the tank if your a person
 */
UCLASS()
class TOUGHTANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* ATankPlayerController::GetControlledTank() const;
	virtual void BeginPlay() override;
	
	
};
