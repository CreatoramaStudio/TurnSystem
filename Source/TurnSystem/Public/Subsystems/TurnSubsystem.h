// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TurnSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTurnUpdate,APawn*,Pawn);
/**
 * 
 */
UCLASS()
class TURNSYSTEM_API UTurnSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	UPROPERTY(BlueprintAssignable, Category = "Turn System")
	FTurnUpdate OnTurnStarted;

	UPROPERTY(BlueprintAssignable, Category = "Turn System")
	FTurnUpdate OnTurnFinished;

	UPROPERTY(BlueprintAssignable, Category = "Turn System")
	FTurnUpdate OnPawnAdded;

	UPROPERTY(BlueprintAssignable, Category = "Turn System")
	FTurnUpdate OnPawnRemoved;

	protected:

	UPROPERTY()
	TArray<APawn*> Pawns;

	int32 Index;

	private:

	public:

	UTurnSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintPure,Category = "Turn System")
	TArray<APawn*> GetPawns() const;

	UFUNCTION(BlueprintPure,Category = "Turn System")
	int32 GetIndex() const;

	UFUNCTION(BlueprintPure,Category = "Turn System")
	APawn* GetActivePawn();

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void AddPawn(APawn* Pawn);

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void RemovePawn(APawn* Pawn);

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void RemoveDestroyedPawns();

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	bool ContainsPawn(APawn* Pawn) const;

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void ClearPawns();

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void StartTurn();

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void FinishTurn();

	protected:

	private:
};
