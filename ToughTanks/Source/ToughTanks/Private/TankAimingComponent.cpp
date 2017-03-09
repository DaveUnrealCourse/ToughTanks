// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "Projectile.h"
#include "BarrelPri.h"
#include "BarrelSec.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;//TODO should this really tick
}
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();// needed for the BP to run its begin play 
	LastFireTimePri = FPlatformTime::Seconds();//so first fire is after the start
}
void UTankAimingComponent::Initialise(UBarrelPri* BarrelPriToSet, UTankTurret* TurretToSet, UBarrelSec* BarrelSecToSet)
{
	BarrelPri = BarrelPriToSet;
	BarrelSec = BarrelSecToSet;
	Turret = TurretToSet;
}
bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(BarrelPri)) { return false; }
	auto BarrelForward = BarrelPri->GetForwardVector();
	return !BarrelForward.Equals(CurrentAimDirection, 0.01);
}
void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (AmmoPri < 1)
	{
		FiringState = EFiringState::AmmoOut;
		//UE_LOG(LogTemp, Warning, TEXT(" Ammo Out"));
	}
	else if ((FPlatformTime::Seconds() - LastFireTimePri) < PriReloadTimeInSeconds)
	{
		FiringState = EFiringState::Reloading;
		//UE_LOG(LogTemp, Warning, TEXT(" Reloading"));
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
		//UE_LOG(LogTemp, Warning, TEXT(" Aiming"));
	}
	else
	{
		FiringState = EFiringState::Locked;
		//UE_LOG(LogTemp, Warning, TEXT("Locked"));
	}
}
EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;
}
int32 UTankAimingComponent::GetPriAmmoCount() const { return AmmoPri; }
int32 UTankAimingComponent::GetSecAmmoCount() const { return AmmoSec; }

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(BarrelPri && Turret)) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = BarrelPri->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeedPri,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		CurrentAimDirection = AimDirection;
		MoveBarrelTowards(AimDirection);
	}
	else
	{
		//auto Name = GetOwner()->GetName();
		//auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%s I Have No Aim Direction"),Name);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(BarrelPri && BarrelSec && Turret)) { return; }
	// get the barrel direction from the suggested project velocity and rase it to mach 
	auto BarrelRotator = BarrelPri->GetForwardVector().Rotation();
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotatorBarrel = AimAsRotator - BarrelRotator;
	auto DeltaRotatorTurret = AimAsRotator - TurretRotator;
	BarrelPri->Elevate(DeltaRotatorBarrel.Pitch);
	BarrelSec->Elevate(DeltaRotatorBarrel.Pitch);
	//Allways yaw the shortest way
	if (DeltaRotatorTurret.Yaw > 180) { DeltaRotatorTurret.Yaw = DeltaRotatorTurret.Yaw - 360; }
	Turret->Azimuth(DeltaRotatorTurret.Yaw);
}
void UTankAimingComponent::FirePri()
{
	if (FiringState == EFiringState::Locked || FiringState == EFiringState::Aiming)
	{

		if (!ensure(BarrelPri)) { return; }
		if (!ensure(PriProjectileBluePrint)) { return; }
		//spawn a PROJECTILE
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			PriProjectileBluePrint,
			BarrelPri->GetSocketLocation(FName("Projectile")),
			BarrelPri->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeedPri);
		LastFireTimePri = FPlatformTime::Seconds();
		AmmoPri--;
	}
}
void UTankAimingComponent::FireSec()
{

	if (!ensure(BarrelSec)) { return; }
	if (!ensure(SecProjectileBluePrint)) { return; }
	//spawn a PROJECTILE
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		SecProjectileBluePrint,
		BarrelSec->GetSocketLocation(FName("Projectile")),
		BarrelSec->GetSocketRotation(FName("Projectile"))
		);
	Projectile->LaunchProjectile(LaunchSpeedSec);
	LastFireTimeSec = FPlatformTime::Seconds();
	AmmoSec--;
}