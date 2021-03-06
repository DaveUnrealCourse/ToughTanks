// Copyright Dead Weight Dave Inc 2017
#pragma once
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// must be the last include

//class ATank;// forward declaration
class UTankAimingComponent;
//class ATank;
// Responsible for helping the player be controlled

UCLASS()
class TOUGHTANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
/*	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;//crossXlocation
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.3333;
		*///in case i fuck this up i have this part saved TODO get rid of this
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "crosshair")
		float CrossHairXLocation = 0.5;//crossXlocation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "crosshair")
		float CrossHairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 6000000;

	UFUNCTION(BlueprintCallable, Category = State)
		void BP_ChangeState_Spectator();

	UFUNCTION(BlueprintCallable, Category = State)
		void BP_ChangeState_Player();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);
//	UFUNCTION(BlueprintCallable, Category = "Setup")
	//	ATank* GetControlldTank() const;
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")//BlueprintImplementableEvent, Category = "Dead")
	void OnPossessedTankDeath();
private:
	virtual void BeginPlay() override;
	
	//On Death Stuff
	virtual void SetPawn(APawn* InPawn) override;

	//End Of Death Stuff

	virtual void Tick(float DeltaSeconds) override;
	//start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	//Return a OUT Parmeter ture if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;/*
	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;//crossXlocation
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 6000000;
	//UPROPERTY(EditDefaultsOnly, Category = "Health")
	//	float StartingHealth = 100;*/

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
