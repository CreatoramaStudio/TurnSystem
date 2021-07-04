// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystems/TurnSubsystem.h"
#include "LogTurnSystem.h"
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
	OnControllerAdded.IsBound() ? OnControllerAdded.Broadcast(Controller) : FLogTurnSystem::Info("UTurnSubsystem::AddController OnControllerAdded.IsBound is false");
}

void UTurnSubsystem::RemoveController(AController* Controller)
{
	Controllers.RemoveSingle(Controller);
	OnControllerRemoved.IsBound() ? OnControllerRemoved.Broadcast(Controller) : FLogTurnSystem::Info("UTurnSubsystem::RemoveController OnControllerRemoved.IsBound is false");
}

void UTurnSubsystem::RemoveDestroyedControllers()
{
	Controllers.Remove(nullptr);
	OnControllerRemoved.IsBound() ? OnControllerRemoved.Broadcast(nullptr) : FLogTurnSystem::Info("UTurnSubsystem::RemoveDestroyedControllers OnControllerRemoved.IsBound is false");
}

void UTurnSubsystem::ClearControllers()
{
	Index = 0;
	Controllers.Empty();
}

void UTurnSubsystem::StartTurn()
{
	ITurn::Execute_TurnStarted(Controllers[Index]);
	OnTurnStarted.IsBound() ? OnTurnStarted.Broadcast(Controllers[Index]) : FLogTurnSystem::Info("UTurnSubsystem::StartTurn OnTurnStarted.IsBound is false");
}

void UTurnSubsystem::FinishTurn()
{
	ITurn::Execute_TurnEnded(Controllers[Index]);
	OnTurnFinished.IsBound() ? OnTurnFinished.Broadcast(Controllers[Index]) : FLogTurnSystem::Info("UTurnSubsystem::FinishTurn OnTurnFinished.IsBound is false");

	Index++;
	if (Index >= Controllers.Num())
	{
		Index = 0;
	}

	StartTurn();
}
