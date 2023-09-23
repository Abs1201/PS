// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/EditableText.h>
#include <Components/Button.h>
#include <Components/Slider.h>
#include <Components/TextBlock.h>
#include "PSUserSettingsWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UPSUserSettingsWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
	void InitComponents();
	void BindEvents();

	UFUNCTION()
	void OnWidthChanged(const FText& Text);
	UFUNCTION()
	void OnHeightChanged(const FText& Text);
	UFUNCTION()
	void OnFullscreenClicked();
	UFUNCTION()
	void OnBorderlessClicked();
	UFUNCTION()
	void OnWindowedClicked();
	UFUNCTION()
	void OnMouseSensitivityChanged(float Value);
	UFUNCTION()
	void OnBrightnessChanged(float Value);
	UFUNCTION()
	void OnExitClicked();
	UFUNCTION()
	void OnResetClicked();

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> EditWidth;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> EditHeight;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonFullscreen;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonBorderless;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonWindowed;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USlider> SliderMouseSensitivity;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextMouseSensitivity;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USlider> SliderBrightness;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextBrightness;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> ButtonExit;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UButton> ButtonReset;
	
};
