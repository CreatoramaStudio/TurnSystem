// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystems/TurnSubsystem.h"
#include "TurnSystemLog.h"
#include "Interfaces/TurnInterfaces.h"

UTurnSubsystem::UTurnSubsystem()
{
}

void UTurnSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
}

void UTurnSubsystem::Deinitialize()
{
	ClearControllers();
}

TArray<AController*> UTurnSubsystem::GetControllers() const
{
	return Controllers;
}

int32 UTurnSubsystem::GetIndex() const
{
	return Index;
}

AController* UTurnSubsystem::GetActiveController()
{
	return  Controllers[Index];
}

void UTurnSubsystem::AddController(AController* Controller)
{
	Controllers.Add(Controller);
	OnControllerAdded.Broadcast(Controller);
}

void UTurnSubsystem::RemoveController(AController* Controller)
{
	Controllers.RemoveSingle(Controller);
	OnControllerRemoved.Broadcast(Controller);
}

void UTurnSubsystem::RemoveDestroyedControllers()
{
	Controllers.Remove(nullptr);
	OnControllerRemoved.Broadcast(nullptr);
}

void UTurnSubsystem::ClearControllers()
{
	Index = 0;
	Controllers.Empty();
}

void UTurnSubsystem::StartTurn()
{
	ITurn::Execute_TurnStarted(Controllers[Index]);
	OnTurnStarted.Broadcast(Controllers[Index]);
}

void UTurnSubsystem::FinishTurn()
{
	ITurn::Execute_TurnEnded(Controllers[Index]);
	OnTurnFinished.Broadcast(Controllers[Index]);

	Index++;
	if (Index >= Controllers.Num())
	{
		Index = 0;
	}

	StartTurn();
}
