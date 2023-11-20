#include "Room.h"
#include "PaperTileMapComponent.h"


ARoom::ARoom()
{
	PrimaryActorTick.bCanEverTick = true;
	
	TileMapComponent = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponent"));
	TileMapComponentWallLeft = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponentWallLeft"));
	TileMapComponentWallRight = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponentWallRight"));
	TileMapComponentWallDown = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponentWallDown"));
	TileMapComponentWallUp = CreateDefaultSubobject<UPaperTileMapComponent>(TEXT("TileMapComponentWallUp"));
	RootComponent = TileMapComponent;
	TileMapComponentWallLeft->SetupAttachment(RootComponent);
	TileMapComponentWallRight->SetupAttachment(RootComponent);
	TileMapComponentWallDown->SetupAttachment(RootComponent);
	TileMapComponentWallUp->SetupAttachment(RootComponent);
	//TileMapComponent->SetRelativeLocation(FVector(-(SizeWidth/2), 0.0f, SizeHeight/2));
	ApplyVisibility();
	
}

ARoom::ARoom(int _id)
{
	PrimaryActorTick.bCanEverTick = true;
	
	id = _id;
	ApplyVisibility();
}

void ARoom::BeginPlay()
{
	Super::BeginPlay();
	ApplyVisibility();
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

void ARoom::ApplyVisibility()
{

	ChangeVisibility(TileMapComponentWallUp,RoofVisibility);
	ChangeVisibility(TileMapComponentWallDown,FloorVisibility);
	ChangeVisibility(TileMapComponentWallLeft,LeftWallVisibility);
	ChangeVisibility(TileMapComponentWallRight,RightWallVisibility);
}

void ARoom::ChangeVisibility(UPaperTileMapComponent* TileComp, bool isVisible)
{
	if(!TileComp) return;
	
	TileComp->SetVisibility(isVisible);
	
	if(isVisible)
	{
		TileComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}else
	{
		TileComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}


