// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PSSaveGame.h"


void AShooterGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    LoadRank();
}

void AShooterGameModeBase::StartGame()
{
    if(StateOfGame==EStateOfGame::Ready){
        SetStateOfGame(EStateOfGame::Play);
        SetStartTime(FDateTime::Now());
        SetScore(0.f);
        test();
    }
}

void AShooterGameModeBase::EndGame()
{
    if(StateOfGame==EStateOfGame::Play){
        SetStateOfGame(EStateOfGame::End);
        SetEndTime(FDateTime::Now());
        PlayTime = EndTime-StartTime;
        int32 ElapsedSeconds = PlayTime.GetTotalSeconds();
        if(ElapsedSeconds < 180){
            AddScore(180-ElapsedSeconds);
        }
        UpdateRank();
        SaveGame();
        OnEndGame.Broadcast();
    }
}

void AShooterGameModeBase::AddScore(float NewScore)
{
    Score+=NewScore;
}



void AShooterGameModeBase::UpdateRank()
{
    int32 RankIndex=0;
    for(auto e: Scores){
        //UE_LOG(LogTemp, Display, TEXT("Score: %f"), e);
        if(e < Score){
            break;
        }
        ++RankIndex;
    }
    //UE_LOG(LogTemp, Display, TEXT("score_num: %d"), Scores.Num());
    Rank=RankIndex+1;
    Scores.Insert(Score, RankIndex);
    Times.Insert(EndTime, RankIndex);
    if(Scores.Num() > 10 && !Scores.IsEmpty()){
        Scores.Pop();
        Times.Pop();
    }
}


void AShooterGameModeBase::SaveGame()
{
    UPSSaveGame* SaveGameInstance = Cast<UPSSaveGame>(UGameplayStatics::CreateSaveGameObject(UPSSaveGame::StaticClass()));
    if(SaveGameInstance){
        SaveGameInstance->Scores = this->Scores;
        SaveGameInstance->Times = this->Times;

        UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Rank"), 0);
    }
}

void AShooterGameModeBase::LoadRank()
{
    UPSSaveGame* LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::CreateSaveGameObject(UPSSaveGame::StaticClass()));
    LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Rank"), 0));
    if(LoadGameInstance){
        this->Scores = LoadGameInstance->Scores;
        this->Times = LoadGameInstance->Times;
    }
    
}

void AShooterGameModeBase::ResetRank()
{
    // UPSSaveGame* SaveGameInstance = Cast<UPSSaveGame>(UGameplayStatics::CreateSaveGameObject(UPSSaveGame::StaticClass()));
    // if(SaveGameInstance){
    //     SaveGameInstance->Scores.Empty();
    //     SaveGameInstance->Times.Empty();
    // }
    Scores.Empty();
    Times.Empty();
}

void AShooterGameModeBase::test()
{
    int32 RankIndex=0;
    for(auto e: Scores){
        UE_LOG(LogTemp, Display, TEXT("Score: %f"), e);
        if(e < Score){
            break;
        }
        ++RankIndex;
    }
    UE_LOG(LogTemp, Display, TEXT("score_num: %d"), Scores.Num());
    UE_LOG(LogTemp, Display, TEXT("Times_num: %d"), Times.Num());
    Rank=RankIndex+1;
    UE_LOG(LogTemp, Display, TEXT("Score: %f"), Score);
    UE_LOG(LogTemp, Display, TEXT("Rank: %d"), Rank);
}


