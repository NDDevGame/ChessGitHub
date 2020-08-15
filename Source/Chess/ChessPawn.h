// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "ChessPawn.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AChessPawn : public AChessPiece
{
	GENERATED_BODY()
	
public:
	bool bFirstMove = true;
	 bool CheckForValidity(FVector2D InVector);

	bool CheckForValidityOtherSide(FVector2D InVector);
	virtual void Move(FVector Location, class AChessBoard* InChessBoard) override;
};
