// Fill out your copyright notice in the Description page of Project Settings.


#include "PSResultWidget.h"
#include "ShooterGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include <Components/TextBlock.h>
#include <Components/GridPanel.h>
#include <Blueprint/WidgetTree.h>
#include <Components/GridSlot.h>


void UPSResultWidget::NativeConstruct()
{
    GameMode = Cast<AShooterGameModeBase>(UGameplayStatics::GetGameMode(this));

    InitScore();
    InitPlayTime();
    //InitRank();
}

void UPSResultWidget::InitScore()
{
    if(GameMode){
        float Score = GameMode->GetScore();
        FString Text = TEXT("Your Score = ") + FString::SanitizeFloat(Score);
        TextScore->SetText(FText::FromString(Text));
    }
}

void UPSResultWidget::InitPlayTime()
{
    if(GameMode){
        FTimespan PlayTime = GameMode->GetPlayTime();
        FString Hours = FString::FromInt(PlayTime.GetHours());
        FString Minutes = FString::FromInt(PlayTime.GetMinutes());
        FString Seconds = FString::FromInt(PlayTime.GetSeconds());
        FString Milliseconds = FString::FromInt(PlayTime.GetFractionMilli());
        FString Text = TEXT("Your Play Time: ");
        if(PlayTime.GetHours()){
            Text = Text + Hours + TEXT("h ") + Minutes + TEXT("m ") + Seconds + TEXT("s ") + Milliseconds + TEXT("ms");
        }
        else if(PlayTime.GetMinutes()){
            Text = Text + Minutes + TEXT("m ") + Seconds + TEXT("s ") + Milliseconds + TEXT("ms");
        }
        else if(PlayTime.GetSeconds()){
            Text = Text + Seconds + TEXT("s ") + Milliseconds + TEXT("ms");
        }
        else{
            Text = TEXT("error");
        }
        TextPlayTime->SetText(FText::FromString(Text));
    }
}

void UPSResultWidget::InitRank()
{
    if(GameMode){
        TArray<int32> Ranks = GameMode->GetRanks();
        TArray<float> Scores = GameMode->GetScores();
        TArray<FDateTime> Times = GameMode->GetTimes();

        for(int32 i=0; i<Scores.Num(); i++){
            UTextBlock* Rank = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            if(Rank){
                FString s = TEXT("#") + FString::FromInt(i+1);
                Rank->SetText(FText::FromString(s));
                UGridSlot* ChildSlot = RankTable->AddChildToGrid(Rank, i+1, 0);
                ChildSlot->SetNudge(FVector2D(0.0, 20.0 * (i+1)));
            }
            UTextBlock* Score = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            if(Score){
                Score->SetText(FText::AsNumber(Scores[i]));
                UGridSlot* ChildSlot = RankTable->AddChildToGrid(Score, i+1, 1);
                ChildSlot->SetNudge(FVector2D(300.0, 20.0*(i+1)));
            }
            UTextBlock* Time = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            if(Time){
                //https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Misc/FDateTime/ToString/1/
                FString s = Times[i].ToString();
                Time->SetText(FText::FromString(s));
                UGridSlot* ChildSlot = RankTable->AddChildToGrid(Time, i+1, 2);
                ChildSlot->SetNudge(FVector2D(600.0, 20.0*(i+1)));
            }
        }

    }
}
