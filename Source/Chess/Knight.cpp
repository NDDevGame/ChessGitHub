// Fill out your copyright notice in the Description page of Project Settings.


#include "Knight.h"

bool AKnight::CheckForValidity(FVector2D InVector)
{
	FHitResult HitResult;
	FVector StartLocation = GetActorLocation();
	StartLocation.Z += 50.f;
	FVector EndLocation = FVector(InVector.X, InVector.Y, 50);
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility);

	if (HitResult.bBlockingHit)
	{
		AChessPiece* HitChessPiece = Cast<AChessPiece>(HitResult.GetActor());
		if (HitChessPiece && HitChessPiece->bSide != bSide)
		{
			PossibleMoves.Add(InVector);
			return true;
		}
	}
	else
	{
		PossibleMoves.Add(InVector);
		return true;
	}
	return false;
}

void AKnight::Move(FVector Location, class AChessBoard* InChessBoard)
{
	PossibleMoves.Empty();
	SetPositionXYValue(Location);
	//X+1,y-2
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex++;
		TempNextYIndex = TempNextYIndex - 2;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector))
		{
			InChessBoard->ShowWayMove(PossibleMoves);
		}
	}
	//x+2,y-1
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex=TempNextXIndex+2;
		TempNextYIndex--;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector))
		{
			InChessBoard->ShowWayMove(PossibleMoves);
		}
	}
	//X+2,y+1
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex = TempNextXIndex + 2;
		TempNextYIndex++;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector))
		{
			InChessBoard->ShowWayMove(PossibleMoves);
		}
	}
	//x+1, y+2
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex++;
		TempNextYIndex=TempNextYIndex+2;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector))
		{
			InChessBoard->ShowWayMove(PossibleMoves);
		}
	}
	//x-1,y-2
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex++;
		TempNextYIndex = TempNextYIndex - 2;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector))
		{
			InChessBoard->ShowWayMove(PossibleMoves);
		}
	}
	//x-2,y+1
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex = TempNextXIndex - 2;
		TempNextYIndex++;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector))
		{
			InChessBoard->ShowWayMove(PossibleMoves);
		}
	}
	//X-2,y-1
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex = TempNextXIndex - 2;
		TempNextYIndex--;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector))
		{
			InChessBoard->ShowWayMove(PossibleMoves);
		}
	}
	//x-1,y-2
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex--;
		TempNextYIndex = TempNextYIndex - 2;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector))
		{
			InChessBoard->ShowWayMove(PossibleMoves);
		}
	}
}
