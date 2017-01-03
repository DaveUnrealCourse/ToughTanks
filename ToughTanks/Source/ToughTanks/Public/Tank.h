// Copyright Dead Weight Dave Inc 2017

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TOUGHTANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	//called by the engine when actor samage is delt
	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const & DamageEvent,class AController * EventInstigator,AActor * DamageCauser) override;
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 StartingHealth = 100;
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 CurrentHealth = StartingHealth;
	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};
