// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QMMainUI.generated.h"

class UProgressBar;

UCLASS()
class QUESTMASTER_API UQMMainUI : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION()
	void OnHealthChanged(float NewHealth);

	UFUNCTION()
	void OnManaChanged(float NewMana);

	UFUNCTION()
	void OnStaminaChanged(float NewStamina);

	UFUNCTION()
	void OnXPChanged(float NewXP);

protected:

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthProgressBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ManaProgressBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* StaminaProgressBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* XPProgressBar;

	virtual void NativeConstruct() override;
};
