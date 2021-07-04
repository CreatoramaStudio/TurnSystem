// Fill out your copyright notice in the Description page of Project Settings.

#include "LogTurnSystem.h"

DEFINE_LOG_CATEGORY(LogTurnSystem);

void FLogTurnSystem::Info(const FString& String)
{
	UE_LOG(LogTurnSystem, Display, TEXT("%s"), *String);
}

void FLogTurnSystem::Warning(const FString& String)
{
	UE_LOG(LogTurnSystem, Warning, TEXT("%s"), *String);
}

void FLogTurnSystem::Error(const FString& String)
{
	UE_LOG(LogTurnSystem, Error, TEXT("%s"), *String);
}