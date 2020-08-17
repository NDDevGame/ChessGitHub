// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Materials/Material.h"
#include "GameFramework/Actor.h"
#include "ChessBoard.generated.h"
//#include "Containers/Array.h"


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

	UPROPERTY(EditDefaultsOnly)
		TArray<int32> StartFigures = { 2,3,4,5,6,4,3,2,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,3,4,5,6,4,3,2 };

	int32 LastClick =-1;

	UPROPERTY(BlueprintReadWrite)
	TArray<UStaticMeshComponent*> ChessBoard_Mesh;

	UPROPERTY(BlueprintReadWrite)
	TArray<UMaterialInterface*> ChessBoard_Material;

	UPROPERTY(BlueprintReadWrite)
	TArray<FVector2D> ChessBoard;

	UPROPERTY(BlueprintReadWrite)
	float XValue;

	UPROPERTY(BlueprintReadWrite)
	float YValue;

	TArray<class AChessPiece*> ChessPieces;

	int32 Index;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
