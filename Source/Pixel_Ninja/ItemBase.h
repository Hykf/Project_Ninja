// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterBase.h"
#include "PaperSprite.h"
#include "ItemBase.generated.h"

UCLASS()
class PIXEL_NINJA_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AItemBase();

protected:
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	int ItemAmount;
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	FString ItemName;
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	FString ItemDescription;
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	UPaperSprite* Sprite;

	UFUNCTION(BlueprintNativeEvent,Category="Item",BlueprintCallable)
	void UseItem(ACharacterBase* Character);
	
};
