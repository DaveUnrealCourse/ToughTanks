// Copyright Dead Weight Dave Inc 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TOUGHTANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);
	//Max Force in Newtons!!!
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float TrackMaxDrivingFource = 6000000;//Assume 40 ton tank and 1 g of exceleration
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxForwardSpeed = 1;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxReverseSpeed = -1;
private:
	UTankTrack();
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	// this one is wrong --->>>  virtual void TickComponent(float DeltaTime, FActorComponentTickFunction *ThisTickFunction)override;
	//virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;
	void ApplySidewaysForce();
	void DriveTrack();
	float CurrentThrottle = 0;
};
