// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TreasureComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXEL_NINJA_API UTreasureComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTreasureComponent();
	
	UPROPERTY(BlueprintReadWrite)
	int GoldAmount;
	UPROPERTY(BlueprintReadWrite)
	int IronAmount;
	UPROPERTY(BlueprintReadWrite)
	int ChiAmount;
	UPROPERTY(BlueprintReadWrite)
	int RiceAmount;

	UFUNCTION(BlueprintCallable)
	int AddGold(int Amount);

	UFUNCTION(BlueprintCallable)
	int AddIron(int Amount);

	UFUNCTION(BlueprintCallable)
	int AddChi(int Amount);

	UFUNCTION(BlueprintCallable)
	int AddRice(int Amount);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
