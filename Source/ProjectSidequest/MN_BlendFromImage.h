// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Generation/GenerationModule.h"
#include "MN_BlendFromImage.generated.h"


UCLASS()

class PROJECTSIDEQUEST_API UMN_BlendFromImage : public UGenerationModule
{
	GENERATED_BODY()
public:

	UMN_BlendFromImage();

	float GetValue(const FVector& Coordinates) const override;


	UFUNCTION(BlueprintPure, DisplayName = "MN_BlendFromImage", Category = "ProceduralGeneration|Noises")
		static UMN_BlendFromImage* ConstructMN_BlendFromImage(UPARAM(ref) UGenerationModule*& MainModule, 
		UPARAM(ref) UGenerationModule*& AddedModule, UPARAM(ref) UTexture2D*& Image,
		const float StartX = 0.0f, const float BlendStartX = 0.0f, const float EndX = 1.0f, const float BlendEndX = 1.0f,
		const float StartY = 0.0f, const float BlendStartY = 0.0f, const float EndY = 1.0f, const float BlendEndY = 1.0f);

public:

	UGenerationModule* MainModule;
	UGenerationModule* AddedModule;
	UTexture2D* Image;

	float StartX;
	float BlendStartX;
	float EndX;
	float BlendEndX;

	float StartY;
	float BlendStartY;
	float EndY;
	float BlendEndY;
};
