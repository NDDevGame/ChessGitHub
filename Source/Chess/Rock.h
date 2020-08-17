// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "Rock.generated.h"
/**
 * 
 */
UCLASS()
class CHESS_API ARock : public AChessPiece
{
	GENERATED_BODY()
	
public:
	ARock();

	bool CheckForValidity(FVector2D InVector) ;

	virtual void Move(FVector Location, class AChessBoard* InChessBoard) override;
};
