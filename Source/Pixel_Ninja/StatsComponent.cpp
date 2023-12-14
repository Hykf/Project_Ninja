// Fill out your copyright notice in the Description page of Project Settings.


#include "StatsComponent.h"
#include "DamageCategory.h"

// Sets default values for this component's properties
UStatsComponent::UStatsComponent()
{

}


void UStatsComponent::ReceiveDamage(EDamageCategory DamageType, float DamageAmount)
{
	OnGetHit.Broadcast();
	float ReceivedDamage;
	switch (DamageType)
	{
	case EDamageCategory::Magic :
		break;
	case EDamageCategory::Physical:
		ReceivedDamage = DamageAmount * (1 - (Defense/100));
		CurrentHealth = FMath::Clamp(CurrentHealth - ReceivedDamage,0,MaxHealth);
		if(!CurrentHealth) OnDie.Broadcast();
		break;
	case EDamageCategory::TrueDamage:
		CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount,0,MaxHealth);
		if(!CurrentHealth) OnDie.Broadcast();
		break;
		default: break;
	}
}

void UStatsComponent::ReceiveHealing(float HealingAmount)
{
	CurrentHealth = FMath::Clamp(CurrentHealth+HealingAmount,0,MaxHealth);
	OnReceiveHealing.Broadcast();

	if(CurrentHealth==MaxHealth) OnFullRecovery.Broadcast();
}

bool UStatsComponent::CanIUseThis(float ManaCost)
{
	return CurrentMana >= ManaCost;
}

void UStatsComponent::OnExpReceive(float ReceivedExp)
{
	float Rest;
	CurrentExperience += ReceivedExp;
	if(CurrentExperience >= DemandedExperience)
	{
		Rest = (int) CurrentExperience % (int) DemandedExperience;
		CurrentExperience = 0 + Rest;
		LevelUp();
	}
}

void UStatsComponent::LevelUp()
{
	const float LevelUpModifier = 1.15;
	
	MaxHealth = MaxHealth * LevelUpModifier;
	MaxMana = MaxMana * LevelUpModifier;
	MaxSpeed = MaxSpeed * LevelUpModifier;
	Damage = Damage * LevelUpModifier - 0.10; //Magic Number 
	Defense = Defense * LevelUpModifier;
	
	OnLevelUp.Broadcast();
}


