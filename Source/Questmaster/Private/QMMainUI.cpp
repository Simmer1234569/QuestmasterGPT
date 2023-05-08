// Fill out your copyright notice in the Description page of Project Settings.


#include "QMMainUI.h"
#include "QMAttributesComponent.h"
#include "Components/ProgressBar.h"

void UQMMainUI::OnHealthChanged(float NewHealth)
{
	HealthProgressBar->SetPercent(NewHealth * 0.01f);
}

void UQMMainUI::OnManaChanged(float NewMana)
{
	ManaProgressBar->SetPercent(NewMana * 0.01f);
}

void UQMMainUI::OnStaminaChanged(float NewStamina)
{
	StaminaProgressBar->SetPercent(NewStamina * 0.01f);
}

void UQMMainUI::OnXPChanged(float NewXP)
{
	XPProgressBar->SetPercent(NewXP * 0.01f);
}

void UQMMainUI::NativeConstruct()
{
	Super::NativeConstruct();

	UQMAttributesComponent* AttributesComponent = Cast<UQMAttributesComponent>(GetOwningPlayer()->GetPawn()->GetComponentByClass<UQMAttributesComponent>());

	if (AttributesComponent)
	{
		AttributesComponent->OnHealthChanged.AddDynamic(this, &UQMMainUI::OnHealthChanged);
		AttributesComponent->OnManaChanged.AddDynamic(this, &UQMMainUI::OnManaChanged);
		AttributesComponent->OnStaminaChanged.AddDynamic(this, &UQMMainUI::OnStaminaChanged);
		AttributesComponent->OnXPChanged.AddDynamic(this, &UQMMainUI::OnXPChanged);
	}
}
