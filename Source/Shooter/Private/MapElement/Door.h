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

	void OnInteract(class AActor* Actor);


	bool CheckKeys(AActor* Actor);

private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* Door;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UBoxComponent* Box;
	

	/** Popup widget for when the player looks at the Door */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* InteractWidget;

	UPROPERTY(EditAnywhere, Category="Interact")
	TArray<FName> Keys;


protected:
	FTimeline Timeline;
	
	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;

	bool bIsDoorClosed = true;

	UPROPERTY(EditAnywhere)
	float DoorMoveOffset = 200.f;

	UFUNCTION()
	void OpenDoor(float Value);

};
