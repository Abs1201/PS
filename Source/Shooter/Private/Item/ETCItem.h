// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../Item.h"
#include "ETCItem.generated.h"

/**
 * 
 */
UCLASS()
class AETCItem : public AItem
{
	GENERATED_BODY()

public:
	AETCItem();

protected:
	virtual void SetItemProperties(EItemState State) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Key, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ETCItemMesh;


public:
	virtual void EnableCustomDepth() override;
	virtual void DisableCustomDepth() override;
};
