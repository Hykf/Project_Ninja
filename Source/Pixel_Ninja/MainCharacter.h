// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "StatsComponent.h"
#include "MainCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PIXEL_NINJA_API AMainCharacter : public APaperZDCharacter
{
	GENERATED_BODY()
public:
	
	AMainCharacter();
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	class UStatsComponent* Stats;
	
};
