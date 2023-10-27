// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Room.h"
#include "GeneratorRoomTemplates.generated.h"

USTRUCT()
struct FRoomsStruct{
	
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ARoom> RoomClasses;
	
};

UCLASS(BlueprintType)
class PIXEL_NINJA_API URoomDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	//TODO zamienic potem ta jedna liste na dwie MUST[start,koniec,event etc.] i MAY[korytarz pulapka etc.] 
	
	UPROPERTY(EditAnywhere)
	TArray<FRoomsStruct> AvailableRoomsClasses;
	
};