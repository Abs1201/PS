// Fill out your copyright notice in the Description page of Project Settings.


#include "PSStageSelectionWidget.h"
#include "Kismet/GameplayStatics.h"

void UPSStageSelectionWidget::NativeConstruct()
{
    Super::NativeConstruct();
    BindEvents();
}

void UPSStageSelectionWidget::OnExitClicked()
{
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

void UPSStageSelectionWidget::OnStage1ButtonClicked()
{
    UGameplayStatics::OpenLevel(this, FName("TutorialStage"));
}

void UPSStageSelectionWidget::BindEvents()
{
    //ButtonStage1->OnClicked.AddUniqueDynamic(this, &UPSStageSelectionWidget::OnStageButtonClicked);
    ButtonExit->OnClicked.AddUniqueDynamic(this, &UPSStageSelectionWidget::OnExitClicked);
    ButtonStage1->OnClicked.AddUniqueDynamic(this, &UPSStageSelectionWidget::OnStage1ButtonClicked);
}




