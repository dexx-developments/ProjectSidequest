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
		UPARAM(ref) UGenerationModule*& AddedModule, UPARAM(ref) UTexture2D* Image, int32 TileCountX = 1, 
		int32 TileCountY = 1, bool LoopTiles = false);
	
	UGenerationModule* MainModule;
	UGenerationModule* AddedModule;
	UTexture2D* Image;
	int32 TileCountX;
	int32 TileCountY;
	bool LoopTiles;
};
