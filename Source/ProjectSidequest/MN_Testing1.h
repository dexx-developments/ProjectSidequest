// Copyright IDFK

#pragma once

#include "CoreMinimal.h"
#include "Generation/GenerationModule.h"
#include "MN_Testing1.generated.h"

/**
* Noise module that outputs a MN_Testing1 pattern.
* Documentation : http://isaratech.com/docs/noise/generators/checkerboard/
*/
UCLASS()

class PROJECTSIDEQUEST_API UMN_Testing1 : public UGenerationModule
{
GENERATED_BODY()
public:

	UMN_Testing1();

	float GetValue(const FVector& Coordinates) const override;

	/**
	* Create a new MN_Testing1 noise module
	*/
	UFUNCTION(BlueprintPure, DisplayName = "MN_Testing1", Category = "ProceduralGeneration|Noises")
		static UMN_Testing1* ConstructMN_Testing1(UPARAM(ref) UGenerationModule*& MainModule, UPARAM(ref) UGenerationModule*& AddedModule,
			
			const float StartX, const float BlendStartX = 0.0f, const float EndX = 1.0f, const float BlendEndX = 1.0f,
			const float StartY = 0.0f, const float BlendStartY = 0.0f, const float EndY = 1.0f, const float BlendEndY = 1.0f);

public:

	UGenerationModule* MainModule;
	UGenerationModule* AddedModule;

	float StartX;
	float BlendStartX;
	float EndX;
	float BlendEndX;

	float StartY;
	float BlendStartY;
	float EndY;
	float BlendEndY;
};
