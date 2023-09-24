// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */
// MUST SETMOVE IN BLUEPRINT!
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTER_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UTriggerComponent();

protected:
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag;

	//class UMover* Mover;
	bool bHasActor;

	AActor* GetAcceptableActor() const;
	
public:
	FORCEINLINE bool GetHasActor() const{ return bHasActor; }
	// UFUNCTION(BlueprintCallable)
	// void SetMover(UMover* NewMover);
};
