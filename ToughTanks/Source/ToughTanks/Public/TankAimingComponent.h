// Copyright Dead Weight Dave Inc 2017

#pragma once
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for Aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	AmmoOut
};
// forward declaration
class AProjectile;
class UBarrelPri;
class UBarrelSec;
class UTankTurret;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOUGHTANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void BeginPlay();
	// Sets default values for this component's properties
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UBarrelPri* BarrelPriToSet, UTankTurret* TurretToSet, UBarrelSec* BarrelSecToSet);
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void FirePri();
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void FireSec();
	UFUNCTION(BlueprintCallable, Category = "Setup")
		int32 GetAmmoCount() const;

	void AimAt(FVector HitLocation);

	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Reloading;
private:
	UTankAimingComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;
	bool IsBarrelMoving();

	UBarrelPri* BarrelPri = nullptr;
	UBarrelSec* BarrelSec = nullptr;
	UTankTurret* Turret = nullptr;
// Firing main Gun
	UPROPERTY(EditDefaultsOnly, Category = "Primary Firing")
		TSubclassOf<AProjectile> PriProjectileBluePrint;
	UPROPERTY(EditAnywhere, Category = "Primary Firing")// consider EditDefaultsOnly
		int32 AmmoPri = 8;// how much Ammo you start with for main gun
	UPROPERTY(EditDefaultsOnly, Category = "Primary Firing")
		float LaunchSpeedPri = 5000; //TODO find out if this number is even close
	UPROPERTY(EditDefaultsOnly, Category = "Primary Firing")
		float PriReloadTimeInSeconds = 3;

// Firing Secondary Gun
	UPROPERTY(EditDefaultsOnly, Category = "Secondary Firing")
		TSubclassOf<AProjectile> SecProjectileBluePrint;
	UPROPERTY(EditAnywhere, Category = "Secondary Firing")// consider EditDefaultsOnly
		int32 AmmoSec = 99;// how much Ammo you start with for main gun
	UPROPERTY(EditDefaultsOnly, Category = "Secondary Firing")
		float LaunchSpeedSec = 10000; //TODO find out if this number is even close
	UPROPERTY(EditDefaultsOnly, Category = "Secondary Firing")
		float SecReloadTimeInSeconds = .2;

	FVector CurrentAimDirection;
	//void MoveBarrelTowards(FVector AimDirection);

	double LastFireTime = 0;
};
