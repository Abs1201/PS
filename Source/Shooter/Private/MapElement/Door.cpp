// Fill out your copyright notice in the Description page of Project Settings.


#include "MapElement/Door.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"

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

void ADoor::OnInteract(AActor* Actor){
	UE_LOG(LogTemp, Display, TEXT("interacted with door"));
	if(CheckKeys(Actor)){
		if(bIsDoorClosed){
			UE_LOG(LogTemp, Warning, TEXT("it was closed"));
			Timeline.Play();
		}
		else{
			UE_LOG(LogTemp, Warning, TEXT("it was opened"));
			Timeline.Reverse();
		}
		bIsDoorClosed = !bIsDoorClosed;
	}




}

bool ADoor::CheckKeys(AActor* Actor)
{
	bool HasKey = true;
	for(auto& k: Keys){
		bool Check = Actor->ActorHasTag(k);
		HasKey&=Check;
	}
	return HasKey;
}

void ADoor::OpenDoor(float Value)
{
	FVector OriginalLocation = this->GetActorLocation();
	FVector NewLocation = FVector(0, DoorMoveOffset*Value, 0);
	Door->SetRelativeLocation(NewLocation);
}

