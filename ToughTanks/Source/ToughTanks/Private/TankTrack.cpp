// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "TankTrack.h"

// check and see is its the on hit events dummby this is you after a couple of drinks

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;//TODO should this really tick
}
void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//Apply the sideways force
	ApplySidewaysForce();
	//drive the track
	DriveTrack();
	//UE_LOG(LogTemp, Warning, TEXT("%f Throttle"), CurrentThrottle)
	CurrentThrottle = 0;
}

//void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction){}
void UTankTrack::ApplySidewaysForce()
{
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	//calc slipage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//Work-out the required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//calc and aply side ways for (F = m a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() *CorrectionAcceleration) / 2; // because there is 2 tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1.0, 1.9);
}
void UTankTrack::DriveTrack()
{
	//UE_LOG(LogTemp, Warning, TEXT("Tank Track DriveTrack"))
	//TODO clamp Throttle so player cant change Speeds in the input menu
	auto ForceApplied = GetForwardVector() * CurrentThrottle *TrackMaxDrivingFource;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
//auto Time = GetWorld()->GetTimeSeconds();
//auto Name = GetName();
//UE_LOG(LogTemp, Warning, TEXT("%s Throttle is at %f"), *Name, Throttle);


