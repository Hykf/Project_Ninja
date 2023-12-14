// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "SakeBase.generated.h"

/**
 * 
 */
UCLASS()
class PIXEL_NINJA_API ASakeBase : public AItemBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	float SakeValue = 10.0;
	
};
