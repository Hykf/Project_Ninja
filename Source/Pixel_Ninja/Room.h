// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperTileMapActor.h"
#include "Room.generated.h"


UCLASS()
class PIXEL_NINJA_API ARoom : public AActor
{
	GENERATED_BODY()
	
protected:

	ARoom();
	ARoom(int id);
	
	UPROPERTY()
	unsigned int id = 0;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperTileMapComponent* TileMapComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperTileMapComponent* TileMapComponentWallLeft;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperTileMapComponent* TileMapComponentWallRight;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperTileMapComponent* TileMapComponentWallUp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UPaperTileMapComponent* TileMapComponentWallDown;
	
	UPROPERTY()
	float SizeHeight = 640.f;
	
	UPROPERTY()
	float SizeWidth = 320.f;

	UFUNCTION()
	void GenerateRoomContent();

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool FloorVisibility = true  ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool RoofVisibility = true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool LeftWallVisibility = true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool RightWallVisibility = true ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bIsSpecialRoom ;
	
	UFUNCTION()
	int GetId();
	UFUNCTION()
	void SetId(int i);
	
	UFUNCTION()
	float GetSizeHeight() const;
	UFUNCTION()
	float GetSizeWidth() const;
	UFUNCTION()
	void ApplyVisibility();
	UFUNCTION()
	void ChangeVisibility(UPaperTileMapComponent* TileComp, bool isVisible);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
