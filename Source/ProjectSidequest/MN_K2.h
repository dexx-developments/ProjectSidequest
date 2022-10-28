// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenerationModule.h"
#include "K2Node.h"
#include "MN_K2.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSIDEQUEST_API UMN_K2 : public UK2Node
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY()
	class UGenerationModule* Module;
	
};
