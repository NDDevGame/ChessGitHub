// Fill out your copyright notice in the Description page of Project Settings.


#include "King.h"

bool AKing::CheckForValidity(FVector2D InVector)
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

void AKing::Move(FVector Location, class AChessBoard* InChessBoard)
{
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex--;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector) == false)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex++;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector) == false)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextYIndex--;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector) == false)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextYIndex++;
		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector) == false)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex++;
		TempNextYIndex--;

		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector) == false)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex++;
		TempNextYIndex++;

		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector) == false)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex--;
		TempNextYIndex++;

		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector) == false)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
		}

	}
	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
	{
		TempNextXIndex--;
		TempNextYIndex--;

		FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
		if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector) == false)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
		}

	}
	InChessBoard->ShowWayMove(PossibleMoves);
}
