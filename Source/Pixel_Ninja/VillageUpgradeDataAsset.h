// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "Engine/DataAsset.h"
#include "UpgradeStats.h"
#include "VillageUpgradeDataAsset.generated.h"

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
	int UpgradeCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FUpgradeStats> Upgrades;

	// UPROPERTY(EditAnywhere)
	// enum CurrencyType;
};

UCLASS(BlueprintType)
class PIXEL_NINJA_API UVillageUpgradeDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMerchantUpgrade> MerchantUpgrades;
	
};
