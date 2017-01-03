// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
void ATankAIController::BeginPlay() 
{ 
	Super::BeginPlay(); 

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetControlledPawn();
	//if (!ensure(PlayerTank && ControlledTank)) { return; }//this is failing fix it!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!<- yeah you dave
	//Move To Player
	if (!ensure(PlayerTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadis);

	if (!ensure(ControlledTank)) { return; }
	
	//Aim Towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//TODO  if aiming or locked than fire
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->FirePri();
		AimingComponent->FireSec();//TODO add a second ENUM for Sec Fire(right now they dont fire Sec when out of Pri
	}
}

