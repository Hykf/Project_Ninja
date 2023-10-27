// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonManager.h"
#include <random>
#include "Kismet/KismetMathLibrary.h"

ADungeonManager::ADungeonManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ADungeonManager::InitializeDungeon()
{
	if(RoomGenTemplate)
	{
		roomsArray = GenerateRandomRooms();
		SetUpDungeon();
	}else
	{
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, FString::Printf(TEXT("TEMPLATE ERROR")));
	}

}

TArray<ARoom*> ADungeonManager::GetRoomsArray() const
{
	return roomsArray;
}


void ADungeonManager::SetUpDungGen(URoomDataAsset* DA)
{
	RoomGenTemplate = DA;
}

TArray<ARoom*> ADungeonManager::GenerateRandomRooms()
{
	TArray<ARoom*> ArrayToReturn;
	std::mt19937 rng;
	rng.seed(seed);
	unsigned int index = 0;
		
	for(int i = 0; i!=XGridSize*YGridSize ;i++)
	{
		std::uniform_int_distribution<int> distribution(0, RoomGenTemplate->AvailableRoomsClasses.Num() - 1);
		index = distribution(rng);

		
		//index = UKismetMathLibrary::RandomIntegerInRange(0, RoomGenTemplate->AvailableRoomsClasses.Num() - 1);
		auto RoomClass = RoomGenTemplate->AvailableRoomsClasses[index].RoomClasses;
		ARoom* NewRoom = GetWorld()->SpawnActor<ARoom>(RoomClass);
		NewRoom->SetId(i);
		ArrayToReturn.Add(NewRoom);
	}
	
	return  ArrayToReturn;
}

void ADungeonManager::DisplayDungeonInfo()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Start")));
	for(ARoom* room : roomsArray)
	{
		GEngine->AddOnScreenDebugMessage(
			-1, 5.f, FColor::Blue,FString::Printf(TEXT("%d"), room->GetId()));
	}
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("Stop")));
	
}

void ADungeonManager::SetUpDungeon()
{
	Initialize2DGrid();
	int i = 0;

	for (int32 RowIndex = 0; RowIndex < DungeonGrid.Num(); RowIndex++) //X
	{
		for (int32 ColumnIndex = 0; ColumnIndex < DungeonGrid[RowIndex].Num(); ColumnIndex++) //Z
		{
			FVector3d loc = FVector3d(RowIndex*roomsArray[i]->GetSizeHeight(),0,ColumnIndex*roomsArray[i]->GetSizeWidth()); 
			roomsArray[i]->SetActorLocation(loc,0,0);
			DungeonGrid[RowIndex][ColumnIndex] = roomsArray[i];
			i++;
		}
	}

}

void ADungeonManager::Initialize2DGrid()
{
	DungeonGrid.SetNum(XGridSize); 

	for (unsigned int RowIndex = 0; RowIndex < XGridSize; RowIndex++)
	{
		DungeonGrid[RowIndex].SetNum(YGridSize); 
	}
}