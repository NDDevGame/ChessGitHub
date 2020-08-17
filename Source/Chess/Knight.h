// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "Knight.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AKnight : public AChessPiece
{
	GENERATED_BODY()

public:
	AKnight();

	bool CheckForValidity(FVector2D InVector);

	virtual void Move(FVector Location, class AChessBoard* InChessBoard) override;
};
