// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessBoard.h"
#include "ChessPawn.h"
#include "Rock.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "ChessController.h"

// Sets default values
AChessBoard::AChessBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChessBoard::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i <= 63; i++)
	{
		FVector2D SpawnLocation2D;
		FVector SpawnLocation;
		FVector	OutLocation;
		PositionLevelUp(i,SpawnLocation,OutLocation,SpawnLocation2D);
		SpawnLocation2D.X += GetActorLocation().X;
		SpawnLocation2D.Y += GetActorLocation().Y;
		SpawnLocation = FVector(SpawnLocation2D.X, SpawnLocation2D.Y, 0);
		TSubclassOf<AChessPiece> SpawnClass;
		switch (StartFigures[i]) {
		case 1:
			SpawnClass = AChessPawn::StaticClass();
			break;
		case 2:
			SpawnClass = ARock::StaticClass();
			break;
		case 3:
			SpawnClass = AKnight::StaticClass();
			break;
		case 4 :
			SpawnClass = ABishop::StaticClass();
			break;
		case 5 :
			SpawnClass = AQueen::StaticClass();
			break;
		case 6 :
			SpawnClass = AKing::StaticClass();
			break;
		}
		FActorSpawnParameters SpawnParams;
		AChessPiece* SpawnedPiece = Cast<AChessPiece>(GetWorld()->SpawnActor<AChessPiece>(SpawnClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams));
		if (SpawnedPiece) {
			//***************************//
			SpawnedPiece->ConstructPiecesData(i > 20);
		}
	}
	
}

void AChessBoard::ShowWayMove(TArray<FVector2D> InMoves)
{
	// Tim kiem material o day
	// Dung cach nay cho nhanh, cach kia chi dung dc o construction script thoi
	UMaterialInterface* OnClickedMaterial = LoadObject<UMaterialInterface>(this, TEXT("Material'/Game/Material/M_OnClicked.M_OnClicked'"));
	for (int i = 0; i < InMoves.Num() ;i++)
	{
		if (InMoves[i] == ChessBoard[i])
		{
			int32 a = i;
			// Set Material chi ap dung duoc tren skeletal mesh hoac la static mesh
			// Gio em can co material de set
			// Co the lam cach nhu a chi hui chieu
			// Roi do e

			ChessBoard_Mesh[a]->SetMaterial(0, OnClickedMaterial);
		}
	}
}

void AChessBoard::OnClickedChessBoard(FVector InLocation, class AActor* InClickedActor)
{
	int32 OutIndex;
	Position2Index(InLocation, OutIndex);
	UMaterialInterface* OnClickedMaterial = LoadObject<UMaterialInterface>(this, TEXT("Material'/Game/Material/M_OnClicked.M_OnClicked'"));
	if (LastClick == -1)
	{
		LastClick = OutIndex;
		AChessPiece* ClickedPiece = Cast<AChessPiece>(InClickedActor);
		if (ClickedPiece) {
			ClickedPiece->Move(InLocation, this);

			int32 FoundIndex = -1;
			
				bool bFound = ChessPieces.Find(ClickedPiece, FoundIndex);
			if (bFound) {
				Index = FoundIndex;
			}


		}
	}
	else
	{
		if (ChessBoard_Mesh[OutIndex]->GetMaterial(0) ==  OnClickedMaterial)
		{
			for (int i = 0; i <= ChessBoard_Mesh.Num(); i++)
			{
				ChessBoard_Mesh[i]->SetMaterial(0,ChessBoard_Material[i]);
			}
			FHitResult HitResult;
			FVector StartLocation;
			FVector B;
			FVector2D A;
			PositionLevelUp(OutIndex, StartLocation, B, A);

			FVector EndLocation = FVector(StartLocation.X, StartLocation.Y, 50);
			GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility);
			if (HitResult.bBlockingHit)
			{
				HitResult.GetActor()->Destroy();
			}
			ChessPieces[Index]->SetActorLocation(StartLocation);
			LastClick = -1;
			AChessController* MyController = Cast<AChessController>(GetWorld()->GetFirstPlayerController());
			if (MyController) {
				AChessPawn* CurrentPawn = Cast<AChessPawn>(MyController->CurrentSelectedChessPiece);
				if (CurrentPawn) {
					CurrentPawn->bFirstMove = false;
				}
			}
		
			

		}
		else
		{
			for (int i = 0; i <= ChessBoard_Mesh.Num(); i++)
			{
				ChessBoard_Mesh[i]->SetMaterial(0,ChessBoard_Material[i]);
			}
			LastClick = -1;
		}
	}
}

void AChessBoard::Index2Position(int32 A, FVector& OutLocation3, FVector2D& OutLocation2D)
{
	OutLocation3 = FVector(A / 8 * 400, A % 8 * 400, 0);
	OutLocation2D = FVector2D(A / 8 * 400, A % 8 * 400);
}

void AChessBoard::PositionLevelUp(int32 A, FVector& OutLocation200, FVector& OutLocation, FVector2D& OutLocation2D)
{
	Index2Position(A, OutLocation200, OutLocation2D);
	OutLocation2D = FVector2D(OutLocation2D.X + 200, OutLocation2D.Y + 200);
	OutLocation200 = FVector(OutLocation2D.X + 200, OutLocation2D.Y + 200,0);
}

void AChessBoard::Position2Index(FVector InLocation, int32& OutIndex)
{
	OutIndex = FMath::FloorToInt(InLocation.X / 400) * 8 + FMath::FloorToInt(InLocation.Y / 400);
}

// Called every frame
void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

