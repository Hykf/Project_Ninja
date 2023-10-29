#include "Room.h"
#include "PaperTileMapComponent.h"


ARoom::ARoom()
{
	PrimaryActorTick.bCanEverTick = true;
	
	TileMapComponent = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponent"));
	//TileMapComponent->SetRelativeLocation(FVector(-(SizeWidth/2), 0.0f, SizeHeight/2));
	
}

ARoom::ARoom(int _id)
{
	PrimaryActorTick.bCanEverTick = true;
	
	id = _id;

}

void ARoom::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoom::GenerateRoomContent()
{
}

int ARoom::GetId()
{
	return id;
}

void ARoom::SetId(int i )
{
	id = i;
}

float ARoom::GetSizeHeight() const
{
	return SizeHeight;
}


float ARoom::GetSizeWidth() const
{
	return SizeWidth;
}


