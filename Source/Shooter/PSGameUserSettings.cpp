// Fill out your copyright notice in the Description page of Project Settings.


#include "PSGameUserSettings.h"

float UPSGameUserSettings::GetMouseSensitivity() const
{
	return MouseSensitivity;
}

void UPSGameUserSettings::SetMouseSensitivity(float Value)
{
	MouseSensitivity = Value;
}

float UPSGameUserSettings::GetAutoExposureBrightness() const
{
	return AutoExposureBrightness;
}

void UPSGameUserSettings::SetAutoExposureBrightness(float Value)
{
	AutoExposureBrightness = Value;
}

void UPSGameUserSettings::SetToDefaults()
{
	Super::SetToDefaults();
	MouseSensitivity = 1.0;
	AutoExposureBrightness = 0.0;
}
