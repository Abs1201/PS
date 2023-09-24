// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Door.generated.h"

UCLASS()
class ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnInteract();

	UFUNCTION()
	void OpenDoor(float Value);

private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* Door;

	/** Line trace collides with box to show HUD widgets */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox;

	/** Popup widget for when the player looks at the item */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* PickupWidget;


protected:
	FTimeline Timeline;
	
	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;

	bool bIsDoorClosed = true;

	UPROPERTY(EditAnywhere)
	float DoorMoveOffset = 400.f;

};
