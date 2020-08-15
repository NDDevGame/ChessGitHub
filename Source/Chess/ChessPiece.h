// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessPiece.generated.h"

UCLASS()
class CHESS_API AChessPiece : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChessPiece();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ChessMesh;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* Box;

	FString Name;

	int32 TempNextYIndex;

	int32 TempNextXIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 IndexLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float XValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float YValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector2D> PossibleMoves;

//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	bool bSet;

	virtual void Move(FVector Location, class AChessBoard* InChessBoard) {};

	void SetPositionXYValue(FVector Position);

	void ConstructPiecesData(bool Side);

	//void IndexToPosition(int32 InIndex, int32& OutXValue, int32& OutYValue);

	//void XYValueToPositionOnBoard(int32 InXValue, int32 InYValue, FVector2D& OutPos);

	//virtual bool CheckForValidity(FVector2D InVector);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
