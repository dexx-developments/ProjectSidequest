// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Generation/GenerationModule.h"
#include "MN_Smoothing.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSIDEQUEST_API UMN_Smoothing : public UGenerationModule
{
	GENERATED_BODY()

public:

	UMN_Smoothing();

	float GetValue(const FVector& Coordinates) const override;


	UFUNCTION(BlueprintPure, DisplayName = "MN_Smoothing", Category = "ProceduralGeneration|Noises")
		static UMN_Smoothing* ConstructMN_Smoothing(UPARAM(ref) UGenerationModule*& Module, 
			int32 SizeX = 2048, int32 SizeY = 2048, float SmoothingEffect = 1.f);


	UGenerationModule* Module;
	int32 SizeX, SizeY;
	float SmoothingEffect;

};
