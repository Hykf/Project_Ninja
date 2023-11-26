// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "TradeType.generated.h"

UENUM(BlueprintType)
enum class ETradeType
{
	Trade,
	CharacterDevelopment,
};

UCLASS()
class PIXEL_NINJA_API UTradeType : public UUserDefinedEnum
{
	GENERATED_BODY()
	
};
