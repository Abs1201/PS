// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include "PSStageSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UPSStageSelectionWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	void BindEvents();

	// UFUNCTION()
	// void OnStageButtonClicked(int32 StageNum);
	UFUNCTION()
	void OnTutorialStageButtonClicked();
	UFUNCTION()
	void OnStage1ButtonClicked();
	UFUNCTION()
	void OnStage2ButtonClicked();
	UFUNCTION()
	void OnStage3ButtonClicked();

	UFUNCTION()
	void OnExitClicked();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Stage)
	int32 ClearedStage=-1;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TArray<TObjectPtr<UButton>> StageButtons;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonStageTutorial;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonStage1;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonStage2;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonStage3;


	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonExit;
};
