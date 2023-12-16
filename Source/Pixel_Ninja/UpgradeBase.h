// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CurrencyType.h"
#include "PaperSprite.h"
#include "UpgradeStats.h"
#include "UpgradeBase.generated.h"

USTRUCT(BlueprintType)
struct FUpgradeStats
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUpgradeStats StatsType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> UpgradesLevel;
};

USTRUCT(BlueprintType)
struct FLevelStats
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EUpgradeStats StatsType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float UpgradesLevel;
};


USTRUCT(BlueprintType)
struct FLevels
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ECurrencyType CurrencyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UpgradeCost;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLevelStats> StatsToChange;


	
};




USTRUCT(BlueprintType)
struct FMerchantUpgrade
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSprite* Sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAvailable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FLevels> Levels;
	
};

/**
 * 
 */
UCLASS(Blueprintable)
class PIXEL_NINJA_API UUpgradeBase : public UDataAsset
{
public:
	
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	FMerchantUpgrade MerchantUpgrade;

	
	
};
