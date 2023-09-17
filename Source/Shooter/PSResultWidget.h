// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PSResultWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UPSResultWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	class AShooterGameModeBase* GameMode;
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<class UTextBlock> TextRank;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<class UTextBlock> TextScore;
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UTextBlock> TextPlayTime;
	// UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	// TObjectPtr<UTextBlock> TextTime;
	

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<class UGridPanel> RankTable;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void InitScore();
	UFUNCTION(BlueprintCallable)
	void InitPlayTime();
	UFUNCTION(BlueprintCallable)
	void InitRank();

	
};
