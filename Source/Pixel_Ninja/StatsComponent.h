// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageCategory.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGetHit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReceiveHealing);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDie);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFullRecovery);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelUp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRespawn);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXEL_NINJA_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatsComponent();

	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FOnGetHit OnGetHit;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FOnReceiveHealing OnReceiveHealing;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FOnDie OnDie;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FOnFullRecovery OnFullRecovery;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FOnLevelUp OnLevelUp;

	UPROPERTY(BlueprintReadWrite)
	int Level = 1 ;
	UPROPERTY(BlueprintReadWrite)
	float CurrentExperience;
	UPROPERTY(BlueprintReadWrite)
	float DemandedExperience = 100;
	UPROPERTY(BlueprintReadWrite)
	float MaxHealth = 100;
	UPROPERTY(BlueprintReadWrite)
	float CurrentHealth = MaxHealth;
	UPROPERTY(BlueprintReadWrite)
	float MaxMana = 100;
	UPROPERTY(BlueprintReadWrite)
	float CurrentMana = MaxMana;
	UPROPERTY(BlueprintReadWrite)
	float MaxSpeed = 450;
	UPROPERTY(BlueprintReadWrite)
	float CurrentSpeed = MaxSpeed;
	UPROPERTY(BlueprintReadWrite)
	float SpeedModifier = 1;
	UPROPERTY(BlueprintReadWrite)
	float Damage = 12;
	UPROPERTY(BlueprintReadWrite)
	float DamageModifier = 1;
	UPROPERTY(BlueprintReadWrite)
	float Defense = 15;
	UPROPERTY(BlueprintReadWrite)
	float DefenseModifier = 1;
	UPROPERTY(BlueprintReadWrite)
	float DefensePenetration = 0.01;
	UPROPERTY(BlueprintReadWrite)
	bool bAlive = true; 
	
	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(EDamageCategory DamageType, float DamageAmount);
	UFUNCTION(BlueprintCallable)
	void ReceiveHealing(float HealingAmount);
	UFUNCTION(BlueprintCallable)
	bool CanIUseThis(float ManaCost);
	UFUNCTION(BlueprintCallable)
	void OnExpReceive(float ReceivedExp);
	UFUNCTION()
	void LevelUp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
