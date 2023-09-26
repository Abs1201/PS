// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../Item.h"
#include "DoorKey.generated.h"

/**
 * 
 */
UCLASS()
class ADoorKey : public AItem
{
	GENERATED_BODY()

public:
	ADoorKey();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ammo, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DoorKeyMesh;
	
};
