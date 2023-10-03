// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FShooterGameModeBaseOnEndGame, AShooterGameModeBase, OnEndGame);
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

protected:
	virtual void BeginPlay() override;

public:
	AShooterGameModeBase();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void StartGame();
	UFUNCTION(BlueprintCallable)
	void EndGame();
	UFUNCTION(BlueprintCallable)
	void AddMonsterScore(float NewMonsterScore);

	UFUNCTION(BlueprintCallable)
	void UpdateRank();
	UFUNCTION(BlueprintCallable)
	void SaveGame();
	UFUNCTION(BlueprintCallable)
	void LoadRank();

	UFUNCTION(BlueprintCallable)
	void ResetRank();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FShooterGameModeBaseOnEndGame OnEndGame;

	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	EStateOfGame StateOfGame;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	FDateTime StartTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	FDateTime EndTime; // Time

	float TimeScore=0;
	float MonsterScore=0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	float Score=0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	FTimespan PlayTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	int32 Rank;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=GameMode)
	float RequiredTime=180;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	TArray<float> Scores;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=GameMode)
	TArray<FDateTime> Times;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=GameMode)
	int32 StageNum;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=GameMode)
	int32 SaveSlotNum = 0;
	

public:
	FORCEINLINE FDateTime GetStartTime(){return StartTime;}
	FORCEINLINE void SetStartTime(FDateTime Time){StartTime=Time;}
	FORCEINLINE FDateTime GetEndTime(){return EndTime;}
	FORCEINLINE void SetEndTime(FDateTime Time){EndTime=Time;}
	FORCEINLINE EStateOfGame GetStateOfGame(){return StateOfGame;} 
	FORCEINLINE void SetStateOfGame(EStateOfGame NewState){StateOfGame=NewState;}

	FORCEINLINE float GetTimeScore(){ return TimeScore; }
	FORCEINLINE void SetTimeScore(float NewTimeScore){ TimeScore=NewTimeScore; }
	FORCEINLINE float GetMonsterScore(){ return MonsterScore; }
	FORCEINLINE void SetMonsterScore(float NewMonsterScore){ MonsterScore = NewMonsterScore; }

	FORCEINLINE float GetScore(){return Score;}
	FORCEINLINE void SetScore(float NewScore){Score=NewScore;}
	FORCEINLINE FTimespan GetPlayTime(){return PlayTime;}
	FORCEINLINE void SetPlayTime(FTimespan NewPlayTime){PlayTime=NewPlayTime;}
	FORCEINLINE int32 GetRank(){return Rank;}
	FORCEINLINE void SetRank(int32 NewRank){Rank=NewRank;}
	FORCEINLINE TArray<float> GetScores(){ return Scores; }
	//FORCEINLINE TArray<FTimespan> GetPlayTimes(){ return PlayTimes;}
	// FORCEINLINE TArray<int32> GetRanks(){ return Ranks; }
	FORCEINLINE TArray<FDateTime> GetTimes(){ return Times; }
	FORCEINLINE int32 GetStageNum() const{ return StageNum; } 
	
};
