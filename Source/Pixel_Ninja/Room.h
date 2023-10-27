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
	
	UPROPERTY()
	float SizeHeight = 320.f;
	
	UPROPERTY()
	float SizeWidth = 160.f;

	UFUNCTION()
	void GenerateRoomContent();
	
public:
	
	UFUNCTION()
	int GetId();
	UFUNCTION()
	void SetId(int i);
	
	UFUNCTION()
	float GetSizeHeight() const;
	UFUNCTION()
	float GetSizeWidth() const;


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
