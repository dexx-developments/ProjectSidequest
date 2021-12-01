// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "M_TestFunctions.generated.h"

UCLASS()
class PROJECTSIDEQUEST_API UM_TestFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		
public:

	UM_TestFunctions();

	UFUNCTION(BlueprintPure, DisplayName = "M_TestFunc", Category = "Max|Testground")
		static float ConstructM_TestFunctions(UPARAM(ref) UTexture2D* Image, int32 PixelX = 5, int32 PixelY = 10);

	UFUNCTION(BlueprintPure, DisplayName = "¨M_ColorTest", Category = "Max|Testground")
		static FColor GetPixelData(UPARAM(ref) UTexture2D* Image, int32 PixelX = 5, int32 PixelY = 10);

	UTexture2D* Image;
	int32 PixelX = 5;
	int32 PixelY = 10;
};
