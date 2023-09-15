// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterGameModeBase.h"
//#include "Misc/DateTime.h"


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
        FTimespan ElapsedTime = EndTime-StartTime;
        ElapsedSeconds = ElapsedTime.GetTotalSeconds();
    }
}

void AShooterGameModeBase::AddScore(float NewScore)
{
    Score+=NewScore;
}
