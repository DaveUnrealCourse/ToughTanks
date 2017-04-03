// Copyright Dead Weight Dave Inc 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Powerup.generated.h"

UCLASS()
class TOUGHTANKS_API APowerup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
