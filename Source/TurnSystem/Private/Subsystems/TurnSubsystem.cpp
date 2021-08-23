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
	ClearPawns();
}

TArray<APawn*> UTurnSubsystem::GetPawns() const
{
	return Pawns;
}

int32 UTurnSubsystem::GetIndex() const
{
	return Index;
}

APawn* UTurnSubsystem::GetActivePawn()
{
	return  Pawns[Index];
}

void UTurnSubsystem::AddPawn(APawn* Pawn)
{
	Pawn->OnDestroyed.AddDynamic(this,&UTurnSubsystem::RemoveDestroyedPawns);
	Pawns.Add(Pawn);
	OnPawnAdded.IsBound() ? OnPawnAdded.Broadcast(Pawn) : FLogTurnSystem::Info("UTurnSubsystem::AddPawn OnPawnAdded.IsBound is false");
}

void UTurnSubsystem::RemovePawn(APawn* Pawn)
{
	Pawn->OnDestroyed.RemoveDynamic(this,&UTurnSubsystem::RemoveDestroyedPawns);
	Pawns.Remove(Pawn);
	OnPawnRemoved.IsBound() ? OnPawnRemoved.Broadcast(Pawn) : FLogTurnSystem::Info("UTurnSubsystem::RemovePawn OnPawnRemoved.IsBound is false");
}

void UTurnSubsystem::RemoveDestroyedPawns(AActor* Actor)
{
	if (APawn* Pawn = Cast<APawn>(Actor))
	{
		RemovePawn(Pawn);
	}	
}

bool UTurnSubsystem::ContainsPawn(APawn* Pawn) const
{
	return Pawns.Contains(Pawn);
}

void UTurnSubsystem::ClearPawns()
{
	Index = 0;
	Pawns.Empty();
}

void UTurnSubsystem::StartTurn()
{
	if (Pawns.IsValidIndex(Index))
	{
		ITurn::Execute_TurnStarted(Pawns[Index]);
		OnTurnStarted.IsBound() ? OnTurnStarted.Broadcast(Pawns[Index]) : FLogTurnSystem::Info("UTurnSubsystem::StartTurn OnTurnStarted.IsBound is false");
	}
}

void UTurnSubsystem::FinishTurn()
{
	if (Pawns.IsValidIndex(Index))
	{
		ITurn::Execute_TurnEnded(Pawns[Index]);
		OnTurnFinished.IsBound() ? OnTurnFinished.Broadcast(Pawns[Index]) : FLogTurnSystem::Info("UTurnSubsystem::FinishTurn OnTurnFinished.IsBound is false");

		Index++;
		if (Index >= Pawns.Num())
		{
			Index = 0;
		}
	}
}
