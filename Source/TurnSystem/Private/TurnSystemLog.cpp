// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnSystemLog.h"

DEFINE_LOG_CATEGORY(LogTurnSystem);

void PrintInfoTurnSystem(const FString& String)
{
	UE_LOG(LogTurnSystem, Display, TEXT("%s"), *String);
}

void PrintWarningTurnSystem(const FString& String)
{
	UE_LOG(LogTurnSystem, Warning, TEXT("%s"), *String);
}

void PrintErrorTurnSystem(const FString& String)
{
	UE_LOG(LogTurnSystem, Error, TEXT("%s"), *String);
}
