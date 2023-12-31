// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "PSSaveGame.h"


void AShooterGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    
}

AShooterGameModeBase::AShooterGameModeBase()
{
    PrimaryActorTick.bStartWithTickEnabled = true; 
    PrimaryActorTick.bCanEverTick = true;
}

void AShooterGameModeBase::Tick(float DeltaTime)
{   
    Super::Tick(DeltaTime);
    if(StateOfGame==EStateOfGame::Play){
        PlayTime = FDateTime::Now() - StartTime;
        float ElapsedTimeSeconds = PlayTime.GetTotalSeconds();
        if(RequiredTime >= ElapsedTimeSeconds){
            SetTimeScore(RequiredTime - ElapsedTimeSeconds);
        }
        SetScore(TimeScore + MonsterScore);
    }

}

void AShooterGameModeBase::StartGame()
{
    if(StateOfGame==EStateOfGame::Ready){
        LoadRank();
        SetStateOfGame(EStateOfGame::Play);
        SetStartTime(FDateTime::Now());
        SetScore(RequiredTime);
    }
}

void AShooterGameModeBase::EndGame()
{
    if(StateOfGame==EStateOfGame::Play){
        SetStateOfGame(EStateOfGame::End);
        SetEndTime(FDateTime::Now());
        PlayTime = EndTime-StartTime;
        UpdateRank();
        SaveGame();
        OnEndGame.Broadcast();
    }
}

void AShooterGameModeBase::AddMonsterScore(float NewMonsterScore)
{
    MonsterScore+=NewMonsterScore;
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
        SaveGameInstance->ClearedStage = FMath::Max(SaveGameInstance->ClearedStage, this->StageNum);

        FString SlotName = "Rank" + FString::FromInt(StageNum);
        UGameplayStatics::SaveGameToSlot(SaveGameInstance, SlotName, 0);
        UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Rank"), 0);
        
    }
}

void AShooterGameModeBase::LoadRank()
{
    UPSSaveGame* LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::CreateSaveGameObject(UPSSaveGame::StaticClass()));

    FString SlotName = "Rank" + FString::FromInt(StageNum);
    LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
    if(LoadGameInstance){
        this->Scores = LoadGameInstance->Scores;
        this->Times = LoadGameInstance->Times;
    }
    else{
        //UE_LOG(LogTemp, Warning, TEXT("loadrank failed"));
    } 
}

//not used.. revised PSUserSettingsWidget create savegameinstance to use itself.
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



