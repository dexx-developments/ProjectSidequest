// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialInterface.h"
#include "Generation/GenerationModule.h"
#include "Landscape.h"
#include "InstancedFoliage.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Foliage/ActorElements.h"
#include "Foliage/FoliageElements.h"


#include "ModdedObjectGenerator.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSIDEQUEST_API UModdedObjectGenerator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

//		/**
//		 * Basic foliage generation (place foliage using the input module)
//		 * @param Module the generation module defining placement probabilities (by default a const module with a probability of 1)
//		 * @param FoliageType the foliage type to place
//		 * @param DiscretizationStep the discretization step
//		 * @param RandomizationRadius the randomization radius around the generated seed
//		 */
//		UFUNCTION(BlueprintCallable, Category = "ProceduralGeneration|Foliage")
//		static UFoliageElements* GenerateObjects(
//			UPARAM(ref) UMetaLandscape*& MetaLandscape,
//			UGenerationModule* Module,
//			const UFoliageType* FoliageType,
//			int DiscretizationStep = 5000,
//			float RandomizationRadius = 500.0f);
//
//	/**
//	* Basic actors generation (place actors using the input module)
//	* @param MetaLandscape the landscape which will received the actors
//	* @param Module the generation module defining placement probabilities (by default a const module with a probability of 1)
//	* @param Template the template of the actor element to place (default spawning parameters)
//	* @param DiscretizationStep the discretization step
//	* @param RandomizationRadius the randomization radius around the generated seed
//	*/
//	UFUNCTION(BlueprintCallable, Category = "ProceduralGeneration|Actors")
//		static UActorElements* GenerateActors(
//			UPARAM(ref) UMetaLandscape*& MetaLandscape,
//			UGenerationModule* Module,
//			const FActorElement& Template,
//			int32 DiscretizationStep = 5000,
//			float RandomizationRadius = 500.0f,
//			bool bRandomYaw = true,
//			float MinZOffset = -5.f,
//			float MaxZOffset = 0.f);
//
//private:
//	static bool CanPlaceInstance(const FVector DesiredLocation, const UFoliageType* FoliageType,
//		TArray<FFoliageElement>& FoliageElements);

	
};
