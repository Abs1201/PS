// Fill out your copyright notice in the Description page of Project Settings.


#include "PSSaveGame.h"


void UPSSaveGame::ResetData()
{
    Scores.Empty();
    Times.Empty();
}

void UPSSaveGame::ResetGame()
{
    ResetData();
    ClearedStage=-1;
}
