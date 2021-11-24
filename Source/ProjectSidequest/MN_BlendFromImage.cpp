// Fill out your copyright notice in the Description page of Project Settings.


#include "MN_BlendFromImage.h"

UMN_BlendFromImage::UMN_BlendFromImage()
{
}

float UMN_BlendFromImage::GetValue(const FVector& Coordinates) const
{
	return AddedModule->GetValue(Coordinates);


	//const float alpha = Image;

	//Image 

	//return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
}

/** I'm mad
* If Coordinates.X <= StartX <= BlendStartX så blir det MainModule
* Else if Coordinates.X <= StartX >= BlendStartX så blir det en graduell blandning mellan Main o Added
* Else if Coordinates.X >= StartX >= BlendStartX så blir det added
* Coordinates.X <= StartX >= BlendStartX
return FMath::Sin((Coordinates.X * XFrequency + Coordinates.Y * YFrequency) * PI); **/

UMN_BlendFromImage* UMN_BlendFromImage::ConstructMN_BlendFromImage(UGenerationModule*& MainModule, 
	UGenerationModule*& AddedModule, UTexture2D*& Image,
	const float StartX, const float BlendStartX, const float EndX, const float BlendEndX, 
	const float StartY, const float BlendStartY, const float EndY, const float BlendEndY)
{
	UMN_BlendFromImage* MN_BlendFromImage = NewObject<UMN_BlendFromImage>();
	MN_BlendFromImage->MainModule = MainModule;
	MN_BlendFromImage->AddedModule = AddedModule;
	MN_BlendFromImage->Image = Image;
	MN_BlendFromImage->StartX = StartX;
	MN_BlendFromImage->BlendStartX = BlendStartX;
	MN_BlendFromImage->EndX = EndX;
	MN_BlendFromImage->BlendEndX = BlendEndX;
	MN_BlendFromImage->StartY = StartY;
	MN_BlendFromImage->BlendStartY = BlendStartY;
	MN_BlendFromImage->EndY = EndY;
	MN_BlendFromImage->BlendEndY = BlendEndY;

	return MN_BlendFromImage;
}
