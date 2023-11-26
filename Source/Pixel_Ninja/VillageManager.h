// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VillageUpgradeDataAsset.h"
#include "GameFramework/Actor.h"
#include "VillageManager.generated.h"

UCLASS()
class PIXEL_NINJA_API AVillageManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVillageManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UVillageUpgradeDataAsset* VillageUpgrades;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
