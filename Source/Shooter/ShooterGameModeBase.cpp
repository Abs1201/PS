// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterGameModeBase.h"
//#include "Misc/DateTime.h"


void AShooterGameModeBase::StartGame()
{
    if(GameState==StateOfGame::Ready){
        SetGameState(StateOfGame::Play);
        SetStartTime(FDateTime::Now());
    }
}

void AShooterGameModeBase::EndGame()
{
    if(GameState==StateOfGame::Play){
        SetGameState(StateOfGame::End);
        SetStartTime(FDateTime::Now());
    }
}
