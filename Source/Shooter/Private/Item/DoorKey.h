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

protected:
	virtual void SetItemProperties(EItemState State) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Key, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DoorKeyMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Key, meta = (AllowPrivateAccess = "true"))
	FName KeyTag;
	

public:
	virtual void EnableCustomDepth() override;
	virtual void DisableCustomDepth() override;

	FORCEINLINE FName GetKeyTag() const{ return KeyTag; }
};
