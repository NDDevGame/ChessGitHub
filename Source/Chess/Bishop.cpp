// Fill out your copyright notice in the Description page of Project Settings.


#include "Bishop.h"

bool ABishop::CheckForValidity(FVector2D InVector)
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
	}
	return false;
}

void ABishop::Move(FVector Location, class AChessBoard* InChessBoard)
{
	PossibleMoves.Empty();
	SetPositionXYValue(Location);
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	for (int i = 0; i <= 7; i++)
	{
		if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
		{
			TempNextXIndex++;
			TempNextYIndex++;
			FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
			if (CheckForValidity(NewVector))
			{
				break;
			}
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	for (int i = 0; i <= 7; i++)
	{
		if (TempNextYIndex <= 7 && TempNextYIndex >= 0)
		{
			TempNextYIndex++;
			TempNextYIndex--;
			FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
			if (CheckForValidity(NewVector))
			{
				break;
			}
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	for (int i = 0; i <= 7; i++)
	{
		if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
		{
			TempNextXIndex--;
			TempNextYIndex--;
			FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
			if (CheckForValidity(NewVector))
			{
				break;
			}
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	for (int i = 0; i <= 7; i++)
	{
		if (TempNextYIndex <= 7 && TempNextYIndex >= 0)
		{
			TempNextYIndex--;
			TempNextYIndex++;
			FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
			if (CheckForValidity(NewVector))
			{
				break;
			}
		}

	}
	InChessBoard->ShowWayMove(PossibleMoves);
}