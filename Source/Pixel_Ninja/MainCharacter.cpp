// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"


AMainCharacter::AMainCharacter()
{
	TreasureComponent = CreateDefaultSubobject<UTreasureComponent>(TEXT("TreasureComp"));
}
