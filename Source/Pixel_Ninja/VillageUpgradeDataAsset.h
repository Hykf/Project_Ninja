// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "Engine/DataAsset.h"
#include "VillageUpgradeDataAsset.generated.h"


USTRUCT(BlueprintType)
struct FMerchantInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentLevel;
	
};

UCLASS(BlueprintType)
class PIXEL_NINJA_API UVillageUpgradeDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMerchantInfo> MerchantInfo;
	
};
