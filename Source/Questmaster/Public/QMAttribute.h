#pragma once

#include "QMAttribute.generated.h"

USTRUCT(BlueprintType)
struct FQMAttribute
{
	GENERATED_BODY()
	
	float CurrentValue = 50.f;
	float MaxValue = 100.f;
	float RegenRate = 2.f;
	float ConsumptionRate = 0.f;

    FQMAttribute() {}
	FQMAttribute(float InConsumptionRate) : ConsumptionRate(InConsumptionRate) {}

	bool TryRegenOnTick(float DeltaTime);
	bool TryConsumeOnTick(float DeltaTime);
};