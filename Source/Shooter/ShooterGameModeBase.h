// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterGameModeBase.generated.h"

/**
 * 
 */
enum class StateOfGame: uint8{
	Ready,
	Play,
	End,
};

UCLASS()
class SHOOTER_API AShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void StartGame();
	void EndGame();
	
protected:
	UPROPERTY(VisibleAnywhere, BluprintReadOnly, Category=GameMode)
	FDateTime StartTime;
	UPROPERTY(VisibleAnywhere, BluprintReadOnly, Cataegory=GameMode)
	FDateTime EndTime;

	UPROPERTY(VisibleAnywhere, BluprintReadOnly, Category=GameMode)
	StateOfGame GameState;

	UPROPERTY(VisibleAnywhere, BluprintReadOnly, Category=GameMode)
	float Score;
	UPROPERTY(VisibleAnywhere, BluprintReadOnly, Category=GameMode)
	int32 Rank;

public:
	FORCEINLINE FDateTime GetStartTime(){return StartTime;}
	FORCEINLINE void SetStartTime(FDateTime Time){StartTime=Time;}
	FORCEINLINE FDateTime GetEndTime(){return EndTime;}
	FORCEINLINE void SetEndTime(FDateTime Time){EndTime=Time;}
	FORCEINLINE StateOfGame GetGameState(){return GameState;} 
	FORCEINLINE void SetGameState(StateOfGame State){GameState=State}
	FORCEINLINE float GetScore(){return Score;}
	FORCEINLINE void SetScore(float NewScore){Score=NewScore;}
	FORCEINLINE int32 GetRank(){return Rank;}
	FORCEINLINE void SetRank(int32 NewRank){Rank=NewRank;}
};
