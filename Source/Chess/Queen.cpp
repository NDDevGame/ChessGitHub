// Fill out your copyright notice in the Description page of Project Settings.


#include "Queen.h"
#include "UObject/ConstructorHelpers.h"

AQueen::AQueen()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/ChessMesh/Queen.Queen'"));
	if (FoundMesh.Succeeded()) {
		ChessMesh->SetStaticMesh(FoundMesh.Object);
	}
}

bool AQueen::CheckForValidity(FVector2D InVector)
{
	FHitResult HitResult;
	FVector StartLocation = GetActorLocation();
	StartLocation.Z += 50.f;
	FVector EndLocation = FVector(InVector.X + 200, InVector.Y + 200, 50);
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility);

	if (HitResult.bBlockingHit)
	{
	
		AChessPiece* HitChessPiece = Cast<AChessPiece>(HitResult.GetActor());
		if (HitChessPiece->bSide != bSide)
		{
			PossibleMoves.Add(InVector);
			return true;
		}
	}
	else
	{
		PossibleMoves.Add(InVector);
		return false;
	}
	return false;
}

void AQueen::Move(FVector Location, class AChessBoard* InChessBoard)
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
			TempNextXIndex++;
			TempNextYIndex++;
			FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
			if (CheckForValidity(NewVector))
			{
				break;
			}
			else
			{
				continue;
			}

		}

	}
	InChessBoard->ShowWayMove(PossibleMoves);

	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	for (int i = 0; i <= 7; i++)
	{
		if (TempNextYIndex <= 7 && TempNextYIndex >= 0 && TempNextXIndex <= 7 && TempNextXIndex >= 0)
		{
			TempNextXIndex++;
			TempNextYIndex--;
			FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
			if (CheckForValidity(NewVector))
			{
				break;
			}
			else
			{
				continue;
			}

		}

	}
	InChessBoard->ShowWayMove(PossibleMoves);

	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	for (int i = 0; i <= 7; i++)
	{
		if (TempNextYIndex <= 7 && TempNextYIndex >= 0 && TempNextXIndex <= 7 && TempNextXIndex >= 0)
		{
			TempNextXIndex--;
			TempNextYIndex--;
			FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
			if (CheckForValidity(NewVector))
			{
				break;
			}
			else
			{
				continue;
			}

		}

	}
	InChessBoard->ShowWayMove(PossibleMoves);

	TempNextXIndex = FMath::FloorToInt(XValue);
	TempNextYIndex = FMath::FloorToInt(YValue);
	for (int i = 0; i <= 7; i++)
	{
		if (TempNextYIndex <= 7 && TempNextYIndex >= 0 && TempNextXIndex <= 7 && TempNextXIndex >= 0)
		{
			TempNextYIndex++;
			TempNextXIndex--;
			FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
			if (CheckForValidity(NewVector))
			{
				break;
			}
			else
			{
				continue;
			}

		}

	}
	InChessBoard->ShowWayMove(PossibleMoves);

}
