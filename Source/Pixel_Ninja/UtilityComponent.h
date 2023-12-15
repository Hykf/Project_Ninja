// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BombBase.h"
#include "SakeBase.h"
#include "Components/ActorComponent.h"
#include "UtilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXEL_NINJA_API UUtilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUtilityComponent();

	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	int ArrowAmount;
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	int FireballAmount;
	UPROPERTY(BlueprintReadWrite)
	ASakeBase* Sake;
	UPROPERTY(BlueprintReadWrite)
	ABombBase* Bomb;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
