// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectSidequestGameMode.h"
#include "ProjectSidequestHUD.h"
#include "ProjectSidequestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectSidequestGameMode::AProjectSidequestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjectSidequestHUD::StaticClass();
}
