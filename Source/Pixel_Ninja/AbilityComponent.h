// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXEL_NINJA_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAbilityComponent();

	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	bool bCanWallJump;
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	bool bCanDoubleJump;
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	bool bCanDash;
	
};
