// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "StatsComponent.h"
#include "CharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class PIXEL_NINJA_API ACharacterBase : public APaperZDCharacter
{
	GENERATED_BODY()
public:
	ACharacterBase();
	
protected:
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	UStatsComponent* Stats;
	
};
