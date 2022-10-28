// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Generation/GenerationModule.h"
#include "MN_Perlin.generated.h"

/**
* Noise module that outputs 3-dimensional Perlin noise.
* Documentation : http://isaratech.com/docs/noise/generators/perlin/
*/
UCLASS()

class PROJECTSIDEQUEST_API UMN_Perlin : public UGenerationModule
{
	GENERATED_BODY()
public:

	UMN_Perlin();

	float GetValue(const FVector& Coordinates) const override;

	/**
	* Create a new Perlin noise module
	*/
	UFUNCTION(BlueprintPure, DisplayName = "MN_Perlin", Category = "ProceduralGeneration|Noises", meta = (AdvancedDisplay = "Seed"))
		static UGenerationModule* ConstructMN_Perlin(const float Frequency = 1.0f, const float Persistence = 0.5f, const float Lacunarity = 2, const int OctaveCount = 6, const int Seed = 0, const float OffsetX = 0, const float OffsetY = 0);
public:

	float Frequency;
	float Persistence;
	int Seed;
	float Lacunarity;
	int OctaveCount;
	float OffsetX;
	float OffsetY;
};