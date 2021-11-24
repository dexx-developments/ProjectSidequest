// Copyright Epic Games, Inc. All Rights Reserved.

using System.Collections.Generic;
using UnrealBuildTool;

public class ProjectSidequest : ModuleRules
{
	public ProjectSidequest(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"WorldBrowser"});
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "ProceduralMeshComponent", "ProceduralMeshComponentEditor", "RuntimeMeshComponent", "Landscape", "AutoLandscapeGenerator", "BlueprintNoiseGenerator", "LandscapeGeneratorRuntime", "Foliage", "FoliageEdit", "WorldBrowser", "LandscapeEditor", "LandscapeEditorUtilities", "Landmass", "LandmassEditor" });
	}
}
