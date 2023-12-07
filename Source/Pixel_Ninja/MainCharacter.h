// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "TreasureComponent.h"
#include "UtilityComponent.h"
#include "MainCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PIXEL_NINJA_API AMainCharacter : public ACharacterBase
{
	GENERATED_BODY()
public:
	
	AMainCharacter();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTreasureComponent* TreasureComponent;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UUtilityComponent* UtilityComponent;
	
};
