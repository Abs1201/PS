// Fill out your copyright notice in the Description page of Project Settings.


#include "PSStageSelectionWidget.h"
#include "Kismet/GameplayStatics.h"
#include "PSSaveGame.h"
#include "Components/Button.h"
#include "Components/Widget.h"

void UPSStageSelectionWidget::NativeConstruct()
{
    Super::NativeConstruct();

    UPSSaveGame* LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::CreateSaveGameObject(UPSSaveGame::StaticClass()));
    LoadGameInstance = Cast<UPSSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Rank"), 0));
    if(LoadGameInstance){
        this->ClearedStage = LoadGameInstance->ClearedStage;
    }

    StageButtons.Add(ButtonStageTutorial);
    StageButtons.Add(ButtonStage1);
    StageButtons.Add(ButtonStage2);
    StageButtons.Add(ButtonStage3);

    for(auto& b: StageButtons){
        b->SetIsEnabled(true);
    }
    for(int32 i=ClearedStage+1; i<StageButtons.Num(); i++){
        StageButtons[i]->SetIsEnabled(false);
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




