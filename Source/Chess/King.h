// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "King.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AKing : public AChessPiece
{
	GENERATED_BODY()
	
public:
	AKing();

	bool CheckForValidity(FVector2D InVector);

	virtual void Move(FVector Location, class AChessBoard* InChessBoard) override;
};
