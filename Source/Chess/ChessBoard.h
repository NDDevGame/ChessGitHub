// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessBoard.generated.h"


UCLASS()
class CHESS_API AChessBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessBoard();

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ShowWayMove(TArray<FVector2D> InMoves);

	void OnClickedChessBoard(FVector InLocation, class AActor* InClickedActor);

	void Index2Position(int32 A, FVector& OutLocation3, FVector2D& OutLocation2D);

	void PositionLevelUp(int32 A, FVector& OutLocation200, FVector& OutLocation, FVector2D& OutLocation2D);

	void Position2Index(FVector InLocation, int32& OutIndex);

	TArray<int32> StartFigures;

	int32 LastClick =-1;

	TArray<UStaticMeshComponent*> ChessBoard_Mesh;

	TArray<UMaterialInterface*> ChessBoard_Material;

	TArray<FVector2D> ChessBoard;

	float XValue;

	float YValue;

	TArray<class AChessPiece*> ChessPieces;

	int32 Index;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
