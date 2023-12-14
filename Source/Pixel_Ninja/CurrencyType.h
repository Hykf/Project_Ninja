#pragma once

#include "CurrencyType.generated.h"

UENUM(BlueprintType)
enum class ECurrencyType : uint8
{
	Gold UMETA(DisplayName = "Gold"),
	Rice  UMETA(DisplayName = "Rice"),
	Iron UMETA(DisplayName = "Iron"),
};