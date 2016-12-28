// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
void ATankAIController::BeginPlay() { Super::BeginPlay(); }

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	//if (!ensure(PlayerTank && ControlledTank)) { return; }//this is failing fix it!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!<- yeah you dave
	if (!ensure(PlayerTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadis);
	if (!ensure(ControlledTank)) { return; }
	//Move To Player
	//Aim Towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//TODO  if aiming or locked than fire
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->FirePri();
	//	AimingComponent->FireSec();
	}
}

