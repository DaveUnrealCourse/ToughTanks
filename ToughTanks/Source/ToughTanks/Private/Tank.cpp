// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "Tank.h"



float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float) StartingHealth;
}

float ATank::GetStartingHealth()
{
	return StartingHealth;
}

float ATank::GetCurrentHealth()
{
	return (float)CurrentHealth;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return DamageToApply;

}
// Called when the game starts or when spawned
//void ATank::BeginPlay(){Super::BeginPlay();}

// Called every frame
//void ATank::Tick( float DeltaTime ){Super::Tick( DeltaTime );}

// Called to bind functionality to input
//void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
//{
//	Super::SetupPlayerInputComponent(InputComponent);
//}

