// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "StatsComponent.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Stats = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats Component"));
}