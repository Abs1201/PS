// Fill out your copyright notice in the Description page of Project Settings.


#include "PSStageSelectionWidget.h"
#include "Kismet/GameplayStatics.h"
#include "PSSaveGame.h"

void UPSStageSelectionWidget::NativeConstruct()
{
    Super::NativeConstruct();

    UPSSaveGame* LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::CreateSaveGameObject(UPSSaveGame::StaticClass()));
    LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Rank"), 0));
    if(LoadGameInstance){
        this->ClearedStage = LoadGameInstance->ClearedStage;
    }


    BindEvents();
}

void UPSStageSelectionWidget::OnExitClicked()
{
    RemoveFromParent();
    UGameplayStatics::OpenLevel(this, FName("Lobby"));
}

// void UPSStageSelectionWidget::OnStageButtonClicked(int32 StageNum)
// {
//     if(StageNum){

//     }
//     FString Text = FString("Stage")+FString::FromInt(StageNum);
//     FName TextName = FName(Text);
//     UGameplayStatics::OpenLevel(GEngine->GetWorld(), TextName);
// }

void UPSStageSelectionWidget::OnTutorialStageButtonClicked()
{
    RemoveFromParent();
    UGameplayStatics::OpenLevel(this, FName("TutorialStage"));
}
void UPSStageSelectionWidget::OnStage1ButtonClicked()
{
    RemoveFromParent();
    UGameplayStatics::OpenLevel(this, FName("Stage1"));
}

void UPSStageSelectionWidget::BindEvents()
{
    //ButtonStage1->OnClicked.AddUniqueDynamic(this, &UPSStageSelectionWidget::OnStageButtonClicked);
    ButtonExit->OnClicked.AddUniqueDynamic(this, &UPSStageSelectionWidget::OnExitClicked);
    ButtonStageTutorial->OnClicked.AddUniqueDynamic(this, &UPSStageSelectionWidget::OnTutorialStageButtonClicked);
    ButtonStage1->OnClicked.AddUniqueDynamic(this, &UPSStageSelectionWidget::OnStage1ButtonClicked);
    
}




