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
class UTankTurret;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOUGHTANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void BeginPlay();
	// Sets default values for this component's properties
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UBarrelPri* BarrelPriToSet, UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void FirePri();
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
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		TSubclassOf<AProjectile> ProjectileBluePrint;
	UPROPERTY(EditAnywhere, Category = "Firing")// consider EditDefaultsOnly
		int32 AmmoPri = 8;// how much Ammo you start with for main gun
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 9000; //TODO find out if this number is even close
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;

	FVector CurrentAimDirection;
	void MoveBarrelTowards(FVector AimDirection);

	double LastFireTime = 0;
};
