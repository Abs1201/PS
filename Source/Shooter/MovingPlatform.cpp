// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += Velocity * DeltaTime;
	
	//get distance 
	float MoveDistance = GetDistanceMoved();
	//apply
	SetActorLocation(CurrentLocation);

	if(MoveDistance > DistanceLimit){
		float gap = MoveDistance - DistanceLimit;
		FString name = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s's gap: %f"), *name, gap);
		FVector MoveDirection = Velocity.GetSafeNormal();
		StartLocation += DistanceLimit * MoveDirection;
		Velocity = -Velocity;
		SetActorLocation(StartLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	//FRotator CurrentRotation = GetActorRotation();
	//CurrentRotation += RotationVelocity * DeltaTime;
	//SetActorRotation(CurrentRotation);
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

float AMovingPlatform::GetDistanceMoved() const
{
    return FVector::Dist(GetActorLocation(), StartLocation);
}
