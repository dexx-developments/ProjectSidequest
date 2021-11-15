// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "LandscapeCreator.generated.h"

UCLASS()
class PROJECTSIDEQUEST_API ALandscapeCreator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALandscapeCreator();

	UPROPERTY()
	class ALandscape* Landscape;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	/*ALandscape* GenerateLandscape();*/

};
