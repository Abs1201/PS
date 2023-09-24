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



	bool CheckKeys(AActor* Actor);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Door;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* Box;
	

	/** Popup widget for when the player looks at the Door */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* InteractWidget;

	UPROPERTY(EditAnywhere, Category="Interact")
	TArray<FName> Keys;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Door", meta = (AllowPrivateAccess = "true"))
	bool bIsDoorClosed = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Door", meta = (AllowPrivateAccess = "true"))
	float DoorMoveOffset = 200.f;

public:
	FORCEINLINE bool GetIsDoorClosed(){ return bIsDoorClosed; }
	FORCEINLINE void SetIsDoorClosed(bool DoorClosed){ bIsDoorClosed = DoorClosed; }
	FORCEINLINE float GetDoorMoveOffset(){ return DoorMoveOffset; }
	FORCEINLINE void SetDoorMoveOffset(float Offset){ DoorMoveOffset=Offset; }
	

};
