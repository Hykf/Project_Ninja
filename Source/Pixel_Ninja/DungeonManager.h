// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <random>
#include "CoreMinimal.h"
#include "Room.h"
#include "GameFramework/Actor.h"
#include "GeneratorRoomTemplates.h"
#include "DungeonManager.generated.h"

UCLASS()
class PIXEL_NINJA_API ADungeonManager : public AActor
{
	GENERATED_BODY()
	
protected:	
	ADungeonManager();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int seed = 42;

	UPROPERTY(EditAnywhere,BlueprintReadWrite) 
	int XGridSize = 8; //MIN 5
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int YGridSize = 6; //MIN 5

	UPROPERTY()
	unsigned int MustRoomNumbers = 2;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	URoomDataAsset* RoomGenTemplate;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<ARoom*> roomsArray; //INIT

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<ARoom*> MustRoomsArray;
	
	TArray<TArray<ARoom*>> DungeonGrid;
	
	UFUNCTION()
	TArray<ARoom*> GenerateRandomRooms();

	UFUNCTION()
	void Initialize2DGrid();

	UFUNCTION()
	void SetUpDungeon();

	UFUNCTION(BlueprintCallable)
	void DisplayDungeonInfo();
	
	UFUNCTION(BlueprintCallable)
	void SetUpDungGen(URoomDataAsset* DA);

	UFUNCTION(BlueprintCallable)
	void InitializeDungeon();

	UFUNCTION()
	void MakeWayFromStartToEnd();

	UFUNCTION()
	void DrawRandomPath(int HowMany,int StartX = 0, int StartY = 0);

	UFUNCTION()
	void DrawPath(int StartX,int StartY, int EndX, int EndY);

	UFUNCTION()
	void OpenWay(int x,int y, int location);

public:
	UFUNCTION(BlueprintCallable)
	TArray<ARoom*> GetRoomsArray() const;
	
	
};
