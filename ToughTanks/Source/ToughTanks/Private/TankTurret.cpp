// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "TankTurret.h"

void UTankTurret::Azimuth(float RelativeSpeed)
{
	// the right amount this frame 
	//do to same for rotation of the turret
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -6, 6);
	auto AzimuthChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewAzimuth = RelativeRotation.Yaw + AzimuthChange;
	SetRelativeRotation(FRotator(0, RawNewAzimuth, 0));
}



