// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	//UE_LOG(LogTemp, Warning, TEXT("Tank Movement initialised"))
}
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//UE_LOG(LogTemp, Warning, TEXT("%f Tank Movement intend Move Forward"), Throw)
	//TODO clamp on throttle so pplayer cant use multi inputs to go faster
}
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//UE_LOG(LogTemp, Warning, TEXT("%f Tank Movement intend Turn Right"), Throw)
	//TODO clamp on throttle so player cant use multi inputs to go faster
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// no need for super we are replacing the fuction
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = (MoveVelocity.GetSafeNormal() +.1);
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);
	UE_LOG(LogTemp, Warning, TEXT("%f vectoring to %f"), ForwardThrow, RightThrow);
}