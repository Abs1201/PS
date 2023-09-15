// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterGameModeBase.h"
//#include "Misc/DateTime.h"


void AShooterGameModeBase::StartGame()
{
    if(StateOfGame==EStateOfGame::Ready){
        SetStateOfGame(EStateOfGame::Play);
        SetStartTime(FDateTime::Now());
    }
}

void AShooterGameModeBase::EndGame()
{
    if(StateOfGame==EStateOfGame::Play){
        SetStateOfGame(EStateOfGame::End);
        SetEndTime(FDateTime::Now());
        // int32 tmp1 = StartTime.GetSecond();
        // int32 tmp2 = EndTime.GetSecond();
        // UE_LOG(LogTemp, Warning, TEXT("StartTime: %d"), tmp1);
        // UE_LOG(LogTemp, Display, TEXT("EndTime: %d"), tmp2);
        FTimespan ElapsedTime = EndTime-StartTime;
        ElapsedSeconds = ElapsedTime.GetTotalSeconds();
        // if(GEngine){
        //     GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("playtime: %d"), ElapsedSeconds));
        // }
    }
}
