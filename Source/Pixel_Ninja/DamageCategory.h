#pragma once

#include "DamageCategory.generated.h"

UENUM(BlueprintType)
enum class EDamageCategory : uint8
{
	None UMETA(DisplayName = "Value One"),
	Physical  UMETA(DisplayName = "Physical Damage"),
	Magic UMETA(DisplayName = "Magic Damage"),
	TrueDamage UMETA(DisplayName = "True Damage")
};