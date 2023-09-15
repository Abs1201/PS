// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterGameModeBase.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EStateOfGame: uint8{
	Ready,
	Play,
	End,
};

UCLASS()
class SHOOTER_API AShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void StartGame();
	UFUNCTION(BlueprintCallable)
	void EndGame();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	FDateTime StartTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	FDateTime EndTime;
	int32 ElapsedSeconds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	EStateOfGame StateOfGame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	float Score;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	int32 Rank;

public:
	FORCEINLINE FDateTime GetStartTime(){return StartTime;}
	FORCEINLINE void SetStartTime(FDateTime Time){StartTime=Time;}
	FORCEINLINE FDateTime GetEndTime(){return EndTime;}
	FORCEINLINE void SetEndTime(FDateTime Time){EndTime=Time;}
	FORCEINLINE EStateOfGame GetStateOfGame(){return StateOfGame;} 
	FORCEINLINE void SetStateOfGame(EStateOfGame NewState){StateOfGame=NewState;}
	FORCEINLINE float GetScore(){return Score;}
	FORCEINLINE void SetScore(float NewScore){Score=NewScore;}
	FORCEINLINE int32 GetRank(){return Rank;}
	FORCEINLINE void SetRank(int32 NewRank){Rank=NewRank;}
};
