#include "QMAttribute.h"

bool FQMAttribute::TryRegenOnTick(float DeltaTime)
{
	if (FMath::IsNearlyEqual(CurrentValue, MaxValue))
	{
		return false;
	}
	
	CurrentValue += RegenRate * DeltaTime;
	CurrentValue = FMath::Clamp(CurrentValue, 0.f, MaxValue);

	return true;
}

bool FQMAttribute::TryConsumeOnTick(float DeltaTime)
{
	ensureAlways(!FMath::IsNearlyZero(ConsumptionRate));
    
	const float NewValue = CurrentValue - ConsumptionRate * DeltaTime;

	if (NewValue < 0.f)
	{
		return false;
	}

	CurrentValue = NewValue;
	return true;
}