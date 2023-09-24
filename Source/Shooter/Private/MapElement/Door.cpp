// Fill out your copyright notice in the Description page of Project Settings.


#include "MapElement/Door.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
	if(CurveFloat){
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoor::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);
}

void ADoor::OnInteract(){
	UE_LOG(LogTemp, Display, TEXT("interacted with door"));

	if(bIsDoorClosed){
		Timeline.Play();
	}
	else{
		Timeline.Reverse();
	}


}

void ADoor::OpenDoor(float Value)
{
	FVector NewLocation = FVector(0, DoorMoveOffset*Value, 0);
	Door->SetRelativeLocation(NewLocation);
}

