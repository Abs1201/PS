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
        if(e < Score){
            break;
        }
        ++RankIndex;
    }
    Rank=RankIndex+1;
    Scores.Insert(Score, RankIndex);
    PlayTimes.Insert(PlayTime, RankIndex);
    //Times.Insert(EndTime, RankIndex);
    if(Scores.Num() > 10){
        Scores.Pop();
        PlayTimes.Pop();
    }
}

void AShooterGameModeBase::SaveGame()
{
    UPSSaveGame* SaveGameInstance = Cast<UPSSaveGame>(UGameplayStatics::CreateSaveGameObject(UPSSaveGame::StaticClass()));
    if(SaveGameInstance){
        SaveGameInstance->Scores = this->Scores;
        SaveGameInstance->PlayTimes = this->PlayTimes;
        SaveGameInstance->Ranks = this->Ranks;

        UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Rank"), 0);
    }
}

void AShooterGameModeBase::LoadRank()
{
    UPSSaveGame* LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::CreateSaveGameObject(UPSSaveGame::StaticClass()));
    LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Rank"), 0));
    if(LoadGameInstance){
        this->Scores = LoadGameInstance->Scores;
        this->PlayTimes = LoadGameInstance->PlayTimes;
        this->Ranks = LoadGameInstance->Ranks;
    }
    
}


