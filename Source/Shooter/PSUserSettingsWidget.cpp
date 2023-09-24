// Fill out your copyright notice in the Description page of Project Settings.Tick


#include "PSUserSettingsWidget.h"
#include "PSGameUserSettings.h"
#include "ShooterGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void UPSUserSettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitComponents();
	BindEvents();
}

void UPSUserSettingsWidget::InitComponents()
{
	UPSGameUserSettings* UserSettings = Cast<UPSGameUserSettings>(GEngine->GetGameUserSettings());
	UE_LOG(LogTemp, Warning, TEXT("testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttest"));
	if(UserSettings==nullptr){ UE_LOG(LogTemp, Display, TEXT("sibal"));}
	if (UserSettings) {
		UE_LOG(LogTemp, Warning, TEXT("asdfasdfasdfasdf"));
		FIntPoint Resolution = UserSettings->GetScreenResolution();
		EditWidth->SetText(FText::AsNumber(Resolution.X));
		EditHeight->SetText(FText::AsNumber(Resolution.Y));

		EWindowMode::Type WindowMode = UserSettings->GetFullscreenMode();
		switch (WindowMode) {
		case EWindowMode::Fullscreen:
			ButtonFullscreen->SetIsEnabled(false);
			break;

		case EWindowMode::WindowedFullscreen:
			ButtonBorderless->SetIsEnabled(false);
			break;

		case EWindowMode::Windowed:
			ButtonWindowed->SetIsEnabled(false);
			break;
		}

		float MouseSensitivity = UserSettings->GetMouseSensitivity();
		SliderMouseSensitivity->SetValue(MouseSensitivity);
		TextMouseSensitivity->SetText(FText::AsNumber(MouseSensitivity));

		float AutoExposureBrightness = UserSettings->GetAutoExposureBrightness();
		float Brightness = (AutoExposureBrightness * -1.0) + 5.0;
		SliderBrightness->SetValue(Brightness);
		TextBrightness->SetText(FText::AsNumber(Brightness));
	}
}

void UPSUserSettingsWidget::BindEvents()
{
	EditWidth->OnTextChanged.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnWidthChanged);
	EditHeight->OnTextChanged.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnHeightChanged);
	ButtonFullscreen->OnClicked.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnFullscreenClicked);
	ButtonBorderless->OnClicked.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnBorderlessClicked);
	ButtonWindowed->OnClicked.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnWindowedClicked);
	SliderMouseSensitivity->OnValueChanged.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnMouseSensitivityChanged);
	SliderBrightness->OnValueChanged.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnBrightnessChanged);
	ButtonExit->OnClicked.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnExitClicked);
    ButtonReset->OnClicked.AddUniqueDynamic(this, &UPSUserSettingsWidget::OnResetClicked);
}

void UPSUserSettingsWidget::OnWidthChanged(const FText& Text)
{
	UPSGameUserSettings* UserSettings = Cast<UPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		if (Text.IsNumeric()) {
			FString String = Text.ToString();
			FIntPoint Resolution = UserSettings->GetScreenResolution();
			int32 Width = FCString::Atoi(*String);
			int32 Height = Resolution.Y;
			if ((Width >= 720) && (Height >= 480)) {
				UserSettings->SetScreenResolution(FIntPoint(Width, Height));
				UserSettings->ApplySettings(false);
			}
			
		}
	}
}

void UPSUserSettingsWidget::OnHeightChanged(const FText& Text)
{
	UPSGameUserSettings* UserSettings = Cast<UPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		if (Text.IsNumeric()) {
			FString String = Text.ToString();
			FIntPoint Resolution = UserSettings->GetScreenResolution();
			int32 Width = Resolution.X;
			int32 Height = FCString::Atoi(*String); 
			if ((Width >= 720) && (Height >= 480)) {
				UserSettings->SetScreenResolution(FIntPoint(Width, Height));
				UserSettings->ApplySettings(false);
			}
		}
	}
}

void UPSUserSettingsWidget::OnFullscreenClicked()
{
	UPSGameUserSettings* UserSettings = Cast<UPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		UserSettings->ApplySettings(false);

		ButtonFullscreen->SetIsEnabled(false);
		ButtonBorderless->SetIsEnabled(true);
		ButtonWindowed->SetIsEnabled(true);
	}
}

void UPSUserSettingsWidget::OnBorderlessClicked()
{
	UPSGameUserSettings* UserSettings = Cast<UPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
		UserSettings->ApplySettings(false);

		ButtonFullscreen->SetIsEnabled(true);
		ButtonBorderless->SetIsEnabled(false);
		ButtonWindowed->SetIsEnabled(true);
	}
}

void UPSUserSettingsWidget::OnWindowedClicked()
{
	UPSGameUserSettings* UserSettings = Cast<UPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {
		UserSettings->SetFullscreenMode(EWindowMode::Windowed);
		UserSettings->ApplySettings(false);

		ButtonFullscreen->SetIsEnabled(true);
		ButtonBorderless->SetIsEnabled(true);
		ButtonWindowed->SetIsEnabled(false);
	}
}

void UPSUserSettingsWidget::OnMouseSensitivityChanged(float Value)
{
	UPSGameUserSettings* UserSettings = Cast<UPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {

		UserSettings->SetMouseSensitivity(Value);
		UserSettings->ApplySettings(false);

		
		TextMouseSensitivity->SetText(FText::AsNumber(Value));
	}
}

void UPSUserSettingsWidget::OnBrightnessChanged(float Value)
{
	UPSGameUserSettings* UserSettings = Cast<UPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings) {

		float AutoExposureBrightness = (Value - 5.0) * -1.0;

		UserSettings->SetAutoExposureBrightness(AutoExposureBrightness);
		UserSettings->ApplySettings(false);

		TextBrightness->SetText(FText::AsNumber(Value));
	}
}

void UPSUserSettingsWidget::OnExitClicked()
{
	RemoveFromParent();
	UE_LOG(LogTemp, Display, TEXT("exitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexitexit"));
}

void UPSUserSettingsWidget::OnResetClicked()
{
    AShooterGameModeBase* GameMode = Cast<AShooterGameModeBase>(UGameplayStatics::GetGameMode(this));
    if(GameMode){
        GameMode->ResetRank();
    }
}