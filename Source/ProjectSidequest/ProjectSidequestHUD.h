// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ProjectSidequestHUD.generated.h"

UCLASS()
class AProjectSidequestHUD : public AHUD
{
	GENERATED_BODY()

public:
	AProjectSidequestHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

