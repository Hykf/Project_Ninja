// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"


AMainCharacter::AMainCharacter():ACharacterBase()
{
	TreasureComponent = CreateDefaultSubobject<UTreasureComponent>(TEXT("TreasureComp"));
	UtilityComponent = CreateDefaultSubobject<UUtilityComponent>(TEXT("UtilityComp"));

	if(!Stats) Stats = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats"));
}
