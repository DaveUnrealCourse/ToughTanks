// Copyright Dead Weight Dave Inc 2017

#include "ToughTanks.h"
#include "Powerup.h"


// Sets default values
APowerup::APowerup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APowerup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

