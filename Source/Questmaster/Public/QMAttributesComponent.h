// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QMAttribute.h"
#include "Components/ActorComponent.h"
#include "QMAttributesComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChanged, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStaminaChanged, float, NewStamina);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnXPChanged, float, NewXP);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTired);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class QUESTMASTER_API UQMAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UQMAttributesComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnTired OnTired;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnManaChanged OnManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnStaminaChanged OnStaminaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnXPChanged OnXPChanged;

	UFUNCTION(BlueprintCallable)
	void ApplyXPChange(float NewValue);
	
	bool TrySprintOnTick(float DeltaTime);

	void RegenOnTick(float DeltaTime);

	bool GetIsSprinting() const;
	void SetSprinting(bool IsSprinting);

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FQMAttribute Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FQMAttribute Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FQMAttribute Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FQMAttribute XP;
	
	bool bIsSprinting;
};
