// Copyright Dead Weight Dave Inc 2017


#include "ToughTanks.h"
#include "Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	
		if (!ensure(ControlledTank)) {UE_LOG(LogTemp, Warning , TEXT("PlayerController BeginPlay Has no Tank"))}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



