// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StatsUpgradeDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FStatsUpgrade
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Value;
};

UCLASS(BlueprintType)
class PIXEL_NINJA_API UStatsUpgradeDataAsset : public UDataAsset
{
	GENERATED_BODY()

	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FStatsUpgrade> StatsUpgrades;
};
