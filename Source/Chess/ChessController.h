// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChessController.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AChessController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	class AChessBoard* Chessboard;

	class AChessPiece* CurrentSelectedChessPiece;

	FVector Location;

	UFUNCTION(BlueprintCallable)
	void HandleClick();
};
