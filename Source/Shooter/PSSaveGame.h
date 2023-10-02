// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PSSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UPSSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	TArray<float> Scores;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	TArray<FDateTime> Times;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	int32 ClearedStage=0;
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	// TArray<int32> Ranks;
	
	

};
