// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TurnSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TURNSYSTEM_API UTurnSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	protected:

	private:

	public:

	UTurnSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	protected:

	private:
};
