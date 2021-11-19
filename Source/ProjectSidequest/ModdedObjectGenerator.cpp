// Fill out your copyright notice in the Description page of Project Settings.


#include "ModdedObjectGenerator.h"

#include "Editor/WorldBrowser/Private/LevelModel.h"
#include "Editor/WorldBrowser/Private/LevelCollectionModel.h"
#include "Editor/WorldBrowser/Private/Tiles/WorldTileDetails.h"
#include "Runtime/Core/Public/Async/ParallelFor.h"
#include "Editor.h"
#include "Misc/FeedbackContext.h"
#include "LandscapeComponent.h"
#include "FoliageType.h"
#include "InstancedFoliageActor.h"
#include "Noise/Perlin.h"
#include "Settings/LevelEditorMiscSettings.h"
#include "Generation/Noise/Const.h"
#include "LandscapeGenerator.h"

//UFoliageElements* UModdedObjectGenerator::GenerateObjects(
//	UMetaLandscape*& MetaLandscape,
//	UGenerationModule* Module,
//	const UFoliageType* FoliageType,
//	int DiscretizationStep,
//	float RandomizationRadius)
//{
//	if (!IsValid(FoliageType))
//	{
//		UE_LOG(LandscapeGenerator, Warning, TEXT("FoliageType is compulsory!"));
//		return NewObject<UFoliageElements>();
//	}
//
//	if (Module == nullptr)
//	{
//		Module = UConst::ConstructConst(1.0f);
//	}
//
//	//GWarn->BeginSlowTask(LOCTEXT("Spawning Foliage", "Initializing generation"), true, true);
//
//	AInstancedFoliageActor* IFA = AInstancedFoliageActor::
//		GetInstancedFoliageActorForLevel(GWorld->GetCurrentLevel(), true);
//
//	// FoliageElements will store the result
//	UFoliageElements* FoliageElements = NewObject<UFoliageElements>();
//	FoliageElements->FoliageType = FoliageType;
//	FoliageElements->MetaLandscape = MetaLandscape;
//
//	int32 MinX, MinY, MaxX, MaxY;
//	MetaLandscape->GetExtent(MinX, MinY, MaxX, MaxY);
//	const FBox& BBox = MetaLandscape->GetBoundingBox();
//	const uint32 Width = 1 + MaxX - MinX;
//	const uint32 Height = 1 + MaxY - MinY;
//	const TArray<float> ProbabilityMap = Module->GetPlaneNoiseMap(Width, Height, 0, 1, 0, 1);
//
//	// Creating the initial seeds population
//	TArray<FVector> Seeds;
//
//	const int32 IterationCount = (BBox.Max.X - BBox.Min.X) * (BBox.Max.Y - BBox.Min.Y) / (DiscretizationStep *
//		DiscretizationStep);
//	int32 Iteration = 0;
//
//	for (int X = BBox.Min.X; X < BBox.Max.X; X += DiscretizationStep)
//	{
//		if (GWarn->ReceivedUserCancel())
//			break;
//
//		//GWarn->StatusUpdate(Iteration, IterationCount, LOCTEXT("Generating objects", "Generating objects"));
//
//		for (int Y = BBox.Min.Y; Y < BBox.Max.Y; Y += DiscretizationStep)
//		{
//			float Alpha = FMath::DegreesToRadians(FMath::Rand() % 360 - 180);
//			float Radius = RandomizationRadius;
//
//			FVector Position = FVector(X + Radius * FMath::Cos(Alpha), Y + Radius * FMath::Sin(Alpha), 0);
//
//			int HeightmapIndex = (Y - BBox.Min.Y) / MetaLandscape->GetActorScale3D().Y * Width + (X - BBox.Min.X) / MetaLandscape
//				->GetActorScale3D().X;
//			float Probability = (ProbabilityMap[HeightmapIndex] + 1.0) / 2.0;
//
//			if (FMath::FRand() < Probability)
//			{
//				Seeds.Add(Position);
//			}
//
//			Iteration++;
//		}
//	}
//
//	// Planting seeds into foliage instances
//	for (FVector& Position : Seeds)
//	{
//		FHitResult Hit;
//		if (ULandscapeGenerator::Trace(Hit, Position))
//		{
//			// Slope check
//			const float MaxNormalAngle = FMath::Cos(FMath::DegreesToRadians(FoliageElements->FoliageType->GroundSlopeAngle.Max));
//			const float MinNormalAngle = FMath::Cos(FMath::DegreesToRadians(FoliageElements->FoliageType->GroundSlopeAngle.Min));
//			if (!(MaxNormalAngle > Hit.ImpactNormal.Z + SMALL_NUMBER || MinNormalAngle < Hit.ImpactNormal.Z - SMALL_NUMBER))
//			{
//				if (CanPlaceInstance(Hit.Location, FoliageElements->FoliageType, FoliageElements->Elements))
//				{
//					// Add potential instance
//					UPrimitiveComponent* HitComponent = Hit.Component.Get();
//					if (FoliageElements->FoliageType->AlignToNormal)
//					{
//						new(FoliageElements->Elements)FFoliageElement(-1, 1, Hit.Location,
//							FPotentialInstance(Hit.Location, Hit.ImpactNormal, HitComponent,
//								1.f));
//					}
//					else
//						new(FoliageElements->Elements)FFoliageElement(-1, 1, Hit.Location,
//							FPotentialInstance(Hit.Location, FVector(0, 0, 1), HitComponent,
//								1.f));
//				}
//			}
//		}
//
//		//		FoliageElements->Elements.Add(FFoliageElement(-1, 1, Position));	// TODO Remove after test
//	}
//
//	GWarn->EndSlowTask();
//
//	return FoliageElements;
//}