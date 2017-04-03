// Copyright Dead Weight Dave Inc 2017

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class TOUGHTANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	//called by the engine when actor damage is delt
	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const & DamageEvent,class AController * EventInstigator,AActor * DamageCauser) override;
	UFUNCTION(Blueprintpure, Category = "Health")
	float GetHealthPercent() const;
	UFUNCTION(Blueprintpure, Category = "Health")
	float GetStartingHealth();
	UFUNCTION(Blueprintpure, Category = "Health")
	float GetCurrentHealth();
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetCurrentHealthUp();
	UPROPERTY(BlueprintAssignable, Category = "Test")//not needed?
	FTankDelegate OnDeath;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;

private:
	ATank();
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 StartingHealth = 100;
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 CurrentHealth;// initalized in begian play
	UPROPERTY(EditDefaultsOnly, Category = "TeamInfo")
	int32 Team = 0;
	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};
