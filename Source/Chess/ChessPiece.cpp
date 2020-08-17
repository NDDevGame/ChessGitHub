// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessPiece.h"
#include "ChessBoard.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AChessPiece::AChessPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ChessMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = ChessMesh;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(RootComponent);
	UMaterialInterface* WhitePiecesMaterial = LoadObject<UMaterialInterface>(this, TEXT("Material'/Game/Material/M_WhiteChess.M_WhiteChess'"));
	UMaterialInterface* BlackPiecesMaterial = LoadObject<UMaterialInterface>(this, TEXT("Material'/Game/Material/M_BlackChess.M_BlackChess'"));
	if (bSide == true)
	{
		ChessMesh->SetMaterial(0,BlackPiecesMaterial);
	}
	else
	{
		ChessMesh->SetMaterial(0,WhitePiecesMaterial);
	}
}

void AChessPiece::SetPositionXYValue(FVector Position)
{
	XValue = FMath::FloorToInt(Position.X / 400);
	YValue = FMath::FloorToInt(Position.Y / 400);
}

void AChessPiece::ConstructPiecesData(bool Side)
{
	bSide = Side;
	UMaterialInterface* WhitePiecesMaterial = LoadObject<UMaterialInterface>(this, TEXT("Material'/Game/Material/M_WhiteChess.M_WhiteChess'"));
	UMaterialInterface* BlackPiecesMaterial = LoadObject<UMaterialInterface>(this, TEXT("Material'/Game/Material/M_BlackChess.M_BlackChess'"));
	if (bSide == true)
	{
		ChessMesh->SetMaterial(0,BlackPiecesMaterial);
	}
	else
	{
		ChessMesh->SetMaterial(0,WhitePiecesMaterial);
	}
}

/*void AChessPiece::IndexToPosition(int32 InIndex, int32& OutXValue, int32& OutYValue)
{

}

void AChessPiece::XYValueToPositionOnBoard(int32 InXValue, int32 InYValue, FVector2D& OutPos)
{

}*/

/*bool AChessPiece::CheckForValidity(FVector2D InVector)
{
	return false;
}*/

// Called when the game starts or when spawned
void AChessPiece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChessPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

