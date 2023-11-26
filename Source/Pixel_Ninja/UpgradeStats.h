// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "UpgradeStats.generated.h"

UENUM(BlueprintType)
enum class EUpgradeStats : uint8
{
	NONE				 UMETA(DisplayName = "NONE"),
	Health				 UMETA(DisplayName = "Health"),
	Mana				 UMETA(DisplayName = "Mana"),
	Speed				 UMETA(DisplayName = "Speed"),
	Defense				 UMETA(DisplayName = "Defense"),
	Damage				 UMETA(DisplayName = "Damage"),
	DefenseModifier      UMETA(DisplayName = "DefenseModifier"),
	DamageModifier       UMETA(DisplayName = "DamageModifier"),
	SpeedModifier		 UMETA(DisplayName = "SpeedModifier")

};

