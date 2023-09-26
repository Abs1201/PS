// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ETCItem.h"
#include "DoorKey.generated.h"

/**
 * 
 */
UCLASS()
class ADoorKey : public AETCItem
{
	GENERATED_BODY()

public:
	ADoorKey();

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Key, meta = (AllowPrivateAccess = "true"))
	FName KeyTag;

public:
	FORCEINLINE FName GetKeyTag() const{ return KeyTag; }
};
