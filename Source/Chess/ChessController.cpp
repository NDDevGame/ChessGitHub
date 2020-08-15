// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessController.h"
#include "Kismet/GameplayStatics.h"
#include "ChessBoard.h"
#include "ChessPiece.h"

void AChessController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AChessBoard::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0) {
		Chessboard = Cast<AChessBoard>(FoundActors[0]);
	}
}

void AChessController::HandleClick()
{
	FHitResult HitResult;
	GetHitResultUnderCursorByChannel(TraceTypeQuery1, true, HitResult);
	Location = HitResult.Location;
	if (Chessboard) {
		Chessboard->OnClickedChessBoard(Location, HitResult.GetActor());
		if (Cast<AChessPiece>(HitResult.GetActor())) {
			CurrentSelectedChessPiece = Cast<AChessPiece>(HitResult.GetActor());
		}
	}
}

