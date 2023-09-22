// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "PSGameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API UPSGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	float GetMouseSensitivity() const;
	UFUNCTION(BlueprintCallable)
	void SetMouseSensitivity(float Value);
	 
	UFUNCTION(BlueprintCallable)
	float GetAutoExposureBrightness() const;
	UFUNCTION(BlueprintCallable)
	void SetAutoExposureBrightness(float Value);

protected:
	virtual void SetToDefaults() override;

protected:
	UPROPERTY(Config)
	float MouseSensitivity;

	UPROPERTY(Config)
		float AutoExposureBrightness;
};
