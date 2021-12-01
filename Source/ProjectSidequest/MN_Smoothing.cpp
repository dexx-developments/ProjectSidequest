// Fill out your copyright notice in the Description page of Project Settings.


#include "MN_Smoothing.h"


UMN_Smoothing::UMN_Smoothing()
{
}

float UMN_Smoothing::GetValue(const FVector& Coordinates) const
{
	const FVector PosX = FVector(Coordinates.X + (SmoothingEffect / SizeX), Coordinates.Y, Coordinates.Z);
	const FVector NegX = FVector(Coordinates.X - (SmoothingEffect / SizeX), Coordinates.Y, Coordinates.Z);
	const FVector PosY = FVector(Coordinates.X, Coordinates.Y + (SmoothingEffect / SizeY), Coordinates.Z);
	const FVector NegY = FVector(Coordinates.X, Coordinates.Y - (SmoothingEffect / SizeY), Coordinates.Z);


	return ((Module->GetValue(Coordinates) + Module->GetValue(PosX) + 
	Module->GetValue(NegX) + Module->GetValue(PosY) + Module->GetValue(NegY)) / 5.f);

	//return NewValue;
}


UMN_Smoothing* UMN_Smoothing::ConstructMN_Smoothing(UGenerationModule*& Module,
	int32 SizeX, int32 SizeY, float SmoothingEffect)
{
	UMN_Smoothing* MN_Smoothing = NewObject<UMN_Smoothing>();
	MN_Smoothing->Module = Module;
	MN_Smoothing->SizeX = SizeX;
	MN_Smoothing->SizeY = SizeY;
	MN_Smoothing->SmoothingEffect = SmoothingEffect;

	return MN_Smoothing;
}
