// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TurnSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTurnUpdate,AController*,Controller);
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
	FTurnUpdate OnControllerAdded;

	UPROPERTY(BlueprintAssignable, Category = "Turn System")
	FTurnUpdate OnControllerRemoved;

	protected:

	UPROPERTY()
	TArray<AController*> Controllers;

	int32 Index;

	private:

	public:

	UTurnSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	TArray<AController*> GetControllers() const;

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	int32 GetIndex() const;

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	AController* GetActiveController();

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void AddController(AController* Controller);

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void RemoveController(AController* Controller);

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void RemoveDestroyedControllers();

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void ClearControllers();

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void StartTurn();

	UFUNCTION(BlueprintCallable,Category = "Turn System")
	void FinishTurn();

	protected:

	private:
};
