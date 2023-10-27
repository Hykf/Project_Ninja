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

	UPROPERTY()
	unsigned int XGridSize = 10;
	
	UPROPERTY()
	unsigned int YGridSize = 10;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	URoomDataAsset* RoomGenTemplate;

	UPROPERTY()
	TArray<ARoom*> roomsArray; //INIT
	
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

public:
	UFUNCTION(BlueprintCallable)
	TArray<ARoom*> GetRoomsArray() const;
	
	
};
