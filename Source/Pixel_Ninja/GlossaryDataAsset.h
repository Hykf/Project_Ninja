// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlossaryEntryType.h"
#include "PaperSprite.h"
#include "Engine/DataAsset.h"
#include "GlossaryDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FGlossaryEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSprite* Sprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGlossaryEntryType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAvailable;
};

UCLASS(BlueprintType)
class PIXEL_NINJA_API UGlossaryDataAsset : public UDataAsset
{
	GENERATED_BODY()

	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGlossaryEntry> GlossaryEntries;
};
