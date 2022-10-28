// Fill out your copyright notice in the Description page of Project Settings.


#include "MN_Perlin.h"

UMN_Perlin::UMN_Perlin()
{
	Seed = FMath::Rand();
}

float UMN_Perlin::GetValue(const FVector& Coordinates) const
{
	float value = 0.0;
	float signal = 0.0;
	float amplitude = 1.0;
	FVector NewCords;
	NewCords.X = Coordinates.X + OffsetX;
	NewCords.Y = Coordinates.Y + OffsetY;
	NewCords.Z = Coordinates.Z;

	FVector vector = NewCords * Frequency;


	for (int curOctave = 0; curOctave < OctaveCount; curOctave++)
	{
		signal = GradientCoherentNoise3D(vector, Seed + curOctave & 0xffffffff);
		value += signal * amplitude;

		// Prepare the next octave.
		vector *= Lacunarity;
		amplitude *= Persistence;
	}

	return value * (1 - Persistence) / (1 - amplitude);
}

UGenerationModule* UMN_Perlin::ConstructMN_Perlin(const float Frequency, const float Persistence, const float Lacunarity,
	const int OctaveCount, const int Seed, const float OffsetX, const float OffsetY)
{
	UMN_Perlin* MN_Perlin = NewObject<UMN_Perlin>();
	MN_Perlin->Frequency = Frequency;
	MN_Perlin->Persistence = Persistence;
	MN_Perlin->Lacunarity = Lacunarity;
	MN_Perlin->OctaveCount = OctaveCount;
	MN_Perlin->Seed = Seed;
	MN_Perlin->OffsetX = OffsetX;
	MN_Perlin->OffsetY = OffsetY;
	return MN_Perlin;
}