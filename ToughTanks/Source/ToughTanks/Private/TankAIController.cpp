// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "Tank.h"
#include "TankAIController.h"
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

	if (!ensure(ControlledTank)) { UE_LOG(LogTemp, Warning, TEXT("AIController BeginPlay Has no Tank")) }
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank)) { UE_LOG(LogTemp, Warning, TEXT("AI couldn't find Player Tank")) return nullptr; }
	return Cast<ATank>(PlayerTank);
}



