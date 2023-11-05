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

TArray<ARoom*> ADungeonManager::GenerateRandomRooms() //InitRooms
{
	TArray<ARoom*> ArrayToReturn;
	std::mt19937 rng;
	rng.seed(seed);
	int tempIndex = 0;
	unsigned int index = 0;
	int RandomNumber = 0;
	MustRoomNumbers = RoomGenTemplate->MustRooms.Num();
	
	for (int i = 0; i != (XGridSize * YGridSize - (2 * XGridSize + 2 * YGridSize)) + 4 ; i++) {
		
		RandomNumber = FMath::RandRange(0, 100);
		
		if (MustRoomNumbers != 0 && RandomNumber > 65) {
			
			std::uniform_int_distribution<int> distribution(0, RoomGenTemplate->MustRooms.Num() - 1);
			index = distribution(rng);
			auto RoomClass = RoomGenTemplate->MustRooms[MustRoomNumbers-1].RoomClasses;
			ARoom* NewRoom = GetWorld()->SpawnActor<ARoom>(RoomClass);
			NewRoom->SetId(i + tempIndex);
			ArrayToReturn.Add(NewRoom);
			MustRoomNumbers--;
			
		} else {
			std::uniform_int_distribution<int> distribution(0, RoomGenTemplate->MayRooms.Num() - 1);
			index = distribution(rng);
			auto RoomClass = RoomGenTemplate->MayRooms[index].RoomClasses;
			ARoom* NewRoom = GetWorld()->SpawnActor<ARoom>(RoomClass);
			NewRoom->SetId(i + tempIndex);
			ArrayToReturn.Add(NewRoom);
		}
		
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
	int j = 0; 
	TArray<ARoom*> BorderRooms;
	FVector3d loc;

	for(int it = 0; it!=(2*XGridSize + 2*YGridSize) ;it++)
	{
		auto RoomClass = RoomGenTemplate->BorderRooms[0].RoomClasses;
		ARoom* NewRoom = GetWorld()->SpawnActor<ARoom>(RoomClass);
		NewRoom->SetId(it);
		BorderRooms.Add(NewRoom);
	}	
	

	for (int32 RowIndex = 0; RowIndex < DungeonGrid.Num(); RowIndex++) //X
	{
		for (int32 ColumnIndex = 0; ColumnIndex < DungeonGrid[RowIndex].Num(); ColumnIndex++) //Z
		{
			if(RowIndex == 0 || ColumnIndex == 0 || ColumnIndex == DungeonGrid[RowIndex].Num()-1 || RowIndex == DungeonGrid.Num()-1 ) //BORDER
			{
				loc = FVector3d(RowIndex*BorderRooms[j]->GetSizeHeight(),0,ColumnIndex*BorderRooms[j]->GetSizeWidth()); 
				BorderRooms[j]->SetActorLocation(loc,0,0);
				DungeonGrid[RowIndex][ColumnIndex] = BorderRooms[j];
				j++;
			}
			else
			{
				if(i < roomsArray.Num())
				{
					loc = FVector3d(RowIndex*roomsArray[i]->GetSizeHeight(),0,ColumnIndex*roomsArray[i]->GetSizeWidth()); 
					roomsArray[i]->SetActorLocation(loc,0,0);
					DungeonGrid[RowIndex][ColumnIndex] = roomsArray[i];
					i++;
				}
			}
		}
	}

	//Dodaj zawartosc BordersRoom to roomArray
}

void ADungeonManager::Initialize2DGrid()
{
	DungeonGrid.SetNum(XGridSize); 

	for (int RowIndex = 0; RowIndex < XGridSize; RowIndex++)
	{
		DungeonGrid[RowIndex].SetNum(YGridSize); 
	}
}