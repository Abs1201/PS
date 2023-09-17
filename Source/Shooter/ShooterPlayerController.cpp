// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "ShooterGameModeBase.h"
#include <Kismet/GameplayStatics.h>

AShooterPlayerController::AShooterPlayerController()
{

}

void AShooterPlayerController::OnEndGame(){
	UUserWidget* Widget = CreateWidget(this, ResultWidget);
	if(Widget){
		Widget->AddToViewport();
	}
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Check our HUDOverlayClass TSubclassOf variable
	if (HUDOverlayClass)
	{
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayClass);
		if (HUDOverlay)
		{
			HUDOverlay->AddToViewport();
			HUDOverlay->SetVisibility(ESlateVisibility::Visible);
		}
	}

	AShooterGameModeBase* GameMode = Cast<AShooterGameModeBase>(UGameplayStatics::GetGameMode(this));
	if(GameMode){
		GameMode->OnEndGame.AddUniqueDynamic(this, &AShooterPlayerController::OnEndGame);
	}
}