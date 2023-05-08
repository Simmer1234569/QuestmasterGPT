// Fill out your copyright notice in the Description page of Project Settings.


#include "QMAttributesComponent.h"

UQMAttributesComponent::UQMAttributesComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	bIsSprinting = false;
	
	Stamina = FQMAttribute(1.f);
}


void UQMAttributesComponent::ApplyXPChange(float NewValue)
{
	XP.CurrentValue = NewValue;

	OnXPChanged.Broadcast(NewValue);
}

bool UQMAttributesComponent::TrySprintOnTick(float DeltaTime)
{
	const bool bIsConsumed = Stamina.TryConsumeOnTick(DeltaTime);
	if (bIsConsumed)
	{
		OnStaminaChanged.Broadcast(Stamina.CurrentValue);
	}

	return bIsConsumed;
}

void UQMAttributesComponent::RegenOnTick(float DeltaTime)
{
	if (Stamina.TryRegenOnTick(DeltaTime))
	{
		OnStaminaChanged.Broadcast(Stamina.CurrentValue);
	}
	
	if (Health.TryRegenOnTick(DeltaTime))
	{
		OnHealthChanged.Broadcast(Health.CurrentValue);
	}
	
	if (Mana.TryRegenOnTick(DeltaTime))
	{
		OnManaChanged.Broadcast(Mana.CurrentValue);
	}
}

bool UQMAttributesComponent::GetIsSprinting() const
{
	return bIsSprinting;
}

void UQMAttributesComponent::SetSprinting(bool IsSprinting)
{
	bIsSprinting = IsSprinting;
}

void UQMAttributesComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UQMAttributesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (bIsSprinting)
	{
		if (!TrySprintOnTick(DeltaTime))
		{
			bIsSprinting = false;
			OnTired.Broadcast();
		}
	}
	else
	{
		RegenOnTick(DeltaTime);
	}
}

