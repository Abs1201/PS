// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "Mover.h"


UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    // if(Mover==nullptr){
    //     UE_LOG(LogTemp, Warning, TEXT("no mover interlocked"));
    //     return;
    // }
    AActor* Actor =GetAcceptableActor();
    if(Actor){
        // UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        // if(Component != nullptr){
        //     Component->SetSimulatePhysics(false);
        // }
        // Mover->SetShouldMove(true);
        bHasActor = true;
    }
    else{
        bHasActor = false;
    }

}

AActor* UTriggerComponent::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for(AActor* Actor: Actors){
        FString s = Actor->GetActorNameOrLabel();
        UE_LOG(LogTemp, Display, TEXT("s: %s"), *s);
        bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
        if(HasAcceptableTag){
            return Actor;
        }
    }
    return nullptr;
}

// void UTriggerComponent::SetMover(UMover* NewMover)
// {
//     Mover = NewMover;
// }

