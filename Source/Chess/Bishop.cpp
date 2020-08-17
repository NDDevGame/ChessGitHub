// Fill out your copyright notice in the Description page of Project Settings.


#include "Bishop.h"
#include "UObject/ConstructorHelpers.h"
#include "DrawDebugHelpers.h"

ABishop::ABishop()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("StaticMesh'/Game/ChessMesh/Bishop.Bishop'"));
	if (FoundMesh.Succeeded()) {
		ChessMesh->SetStaticMesh(FoundMesh.Object);
	}
}

bool ABishop::CheckForValidity(FVector2D InVector)
{
	FHitResult HitResult;
	FVector StartLocation = GetActorLocation();
	StartLocation.Z += 50.f;
	FVector EndLocation = FVector(InVector.X+200, InVector.Y+200, 50);
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility);
	//UE_LOG(LogTemp, Warning, TEXT("bool %s"), HitResult.bBlockingHit ? TEXT("true") : TEXT("false"));
	//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true);
	if (HitResult.bBlockingHit)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Bishop hit %s"), *HitResult.GetActor()->GetName());
		AChessPiece* HitChessPiece = Cast<AChessPiece>(HitResult.GetActor());
		if ( HitChessPiece->bSide != bSide)
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