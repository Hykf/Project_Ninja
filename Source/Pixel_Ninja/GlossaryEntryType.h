// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlossaryEntryType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGlossaryEntryType : uint8
{
	Friendly UMETA(DisplayName="Friendly"),
	Enemy UMETA(DisplayName="Enemy"),
	Item UMETA(DisplayName="Item"),
};