// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PaperSprite.h"
#include "UpgradeStats.h"
#include "VillageEventBase.generated.h"

UENUM(BlueprintType)
enum class  EEventAdjustment : uint8
{
	DoNothing				 UMETA(DisplayName = "Do Nothing"),
	Add				         UMETA(DisplayName = "Increase Value"),
	Decrease				 UMETA(DisplayName = "Decrease Value")
};

UENUM(BlueprintType)
enum class  EEventAdjustmentType : uint8
{
	Health				 UMETA(DisplayName = "Change Health"),
	Mana				 UMETA(DisplayName = "Change Mana"),
	Damage				 UMETA(DisplayName = "Change Damage"),
	Defense				 UMETA(DisplayName = "Change Defense"),
	Speed				 UMETA(DisplayName = "Change Speed"),
	Gold				 UMETA(DisplayName = "Change Gold Amount"),
	Chi				     UMETA(DisplayName = "Change Chi Amount"),
	Iron				 UMETA(DisplayName = "Change Iron Amount"),
	Rice				 UMETA(DisplayName = "Change Rice Amount"),
	Sake				 UMETA(DisplayName = "Change Sake Amount"),
	Bomb				 UMETA(DisplayName = "Change Bomb Amount")
};


USTRUCT(BlueprintType)
struct FEventAdjustment
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEventAdjustment AdjustmentType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (EditCondition = "AdjustmentType != EEventAdjustment::DoNothing"))
	EEventAdjustmentType StatsType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (EditCondition = "AdjustmentType != EEventAdjustment::DoNothing"))
	float StatsValue;
};

USTRUCT(BlueprintType)
struct FEventAnswers
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Answer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEventAdjustment> StatsAdjustments;
	
};



/**
 * 
 */
UCLASS(Blueprintable)
class PIXEL_NINJA_API UVillageEventBase : public UDataAsset
{
public:
	
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperSprite* Sprite;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString EventText;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FEventAnswers> Answers;
	
};
