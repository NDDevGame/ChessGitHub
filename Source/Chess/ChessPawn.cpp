// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessPawn.h"
#include "UObject/ConstructorHelpers.h"

AChessPawn::AChessPawn()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/ChessMesh/Pawn.Pawn'"));
	if (FoundMesh.Succeeded()) {
		ChessMesh->SetStaticMesh(FoundMesh.Object);
	}
}

bool AChessPawn::CheckForValidity(FVector2D InVector)
{

	FHitResult HitResult;
	FVector StartLocation = GetActorLocation();
	StartLocation.Z += 50.f;
	FVector EndLocation = FVector(InVector.X+200, InVector.Y+200, 50);
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
		return false;
		
	}
	return false;

}
bool AChessPawn::CheckForValidityOtherSide(FVector2D InVector)
{
	FHitResult HitResult;
	FVector StartLocation = GetActorLocation();
	StartLocation.Z += 50.f;
	FVector EndLocation = FVector(InVector.X+200, InVector.Y+200, 50);
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
	
	return false;
}

void AChessPawn::Move(FVector Location, class AChessBoard* InChessBoard)
{
	PossibleMoves.Empty();
	SetPositionXYValue(Location);
	
	//BlackFirstStep
	if (bFirstMove == true)
	{
		if (bSide == true)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
			for (int i = 0; i <= 1; i++)
			{
				if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
				{
					TempNextXIndex--;
					FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
					if (CheckForValidity(NewVector)==true)
					{
						break;
					}
					else
					{
						continue;
					}
				}

			}
			//Rid of one White Pieces
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
			if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
			{
				TempNextXIndex--;
				TempNextYIndex++;
				FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
				if (CheckForValidityOtherSide(NewVector)== true)
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
				if (CheckForValidityOtherSide(NewVector) == true)
				{
					TempNextXIndex = FMath::FloorToInt(XValue);
					TempNextYIndex = FMath::FloorToInt(YValue);
				}
			}
		}
		//WhiteFirstStep
		else
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
			for (int i = 0; i <= 1; i++)
			{
				if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
				{
					TempNextXIndex++;
					FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
					if (CheckForValidity(NewVector)==true)
					{
						break;
					}
					else
					{
						continue;
					}
				}

			}
			//Rid of One BlackPieces
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
			if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
			{
				TempNextXIndex++;
				TempNextYIndex++;
				FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
				if (CheckForValidityOtherSide(NewVector) == true)
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
				if (CheckForValidityOtherSide(NewVector) == true)
				{
					TempNextXIndex = FMath::FloorToInt(XValue);
					TempNextYIndex = FMath::FloorToInt(YValue);
				}
			}

		}
	}
	else
	{	//BlackMove
		if (bSide == true)
		{
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
			if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
			{
				TempNextXIndex--;
				FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
				if (CheckForValidity(NewVector) == true || CheckForValidity(NewVector)== false)
				{
					TempNextXIndex = FMath::FloorToInt(XValue);
					TempNextYIndex = FMath::FloorToInt(YValue);
				}

			}
			//Rid of One WhitePieces
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
			if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
			{
				TempNextXIndex--;
				TempNextYIndex++;
				FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
				if (CheckForValidityOtherSide(NewVector) == true)
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
				if (CheckForValidityOtherSide(NewVector) == true)
				{
					TempNextXIndex = FMath::FloorToInt(XValue);
					TempNextYIndex = FMath::FloorToInt(YValue);
				}
			}
		
		}

		//White Move
		else
		{
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
			//Rid of One BlackPieces
			TempNextXIndex = FMath::FloorToInt(XValue);
			TempNextYIndex = FMath::FloorToInt(YValue);
			if (TempNextXIndex <= 7 && TempNextXIndex >= 0)
			{
				TempNextXIndex++;
				TempNextYIndex++;
				FVector2D NewVector = FVector2D(TempNextXIndex * 400, TempNextYIndex * 400);
				if (CheckForValidityOtherSide(NewVector) == true)
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
				if (CheckForValidityOtherSide(NewVector) == true)
				{
					TempNextXIndex = FMath::FloorToInt(XValue);
					TempNextYIndex = FMath::FloorToInt(YValue);
				}
			}


		}
	}
	InChessBoard->ShowWayMove(PossibleMoves);
}
