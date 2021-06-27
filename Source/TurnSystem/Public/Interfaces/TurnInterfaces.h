#pragma once

#include "UObject/Interface.h"
#include "TurnInterfaces.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTurn: public UInterface
{
	GENERATED_BODY()
};

/**
*
*/
class TURNSYSTEM_API ITurn
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Turn System")
	void TurnStarted();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Turn System")
	void TurnEnded();
	
};