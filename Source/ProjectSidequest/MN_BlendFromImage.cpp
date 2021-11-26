// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/Color.h"
#include "MN_BlendFromImage.h"

UMN_BlendFromImage::UMN_BlendFromImage()
{
}

float UMN_BlendFromImage::GetValue(const FVector& Coordinates) const
{
	/*
	FColor* FormatedImageData = static_cast<FColor*>(Image->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_ONLY));
	FTexture2DMipMap* MyMipMap = &Image->PlatformData->Mips[0];
	uint8 PixelX = 5, PixelY = 10;
	uint32 TextureWidth = MyMipMap->SizeX, TextureHeight = MyMipMap->SizeY;
	FColor PixelColor;


	if (PixelX >= 0 && PixelX < TextureWidth && PixelY >= 0 && PixelY < TextureHeight)
	{
		PixelColor = FormatedImageData[PixelY * TextureWidth + PixelX];
	}
	Image->PlatformData->Mips[0].BulkData.Unlock();

	const float alpha = PixelColor.R / 255;

	return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
	
	//return AddedModule->GetValue(Coordinates);
	*/

	//Fixes image for RGB reading
	Image->MipGenSettings.operator=(TMGS_NoMipmaps);
	Image->SRGB = false;
	Image->CompressionSettings.operator=(TC_VectorDisplacementmap);
	FTexture2DMipMap* MyMipMap = &Image->PlatformData->Mips[0];
	FByteBulkData* RawImageData = &MyMipMap->BulkData;
	FColor* FormatedImageData = static_cast<FColor*>(RawImageData->Lock(LOCK_READ_ONLY));
	FColor PixelColor;

	uint32 TextureWidth = MyMipMap->SizeX, TextureHeight = MyMipMap->SizeY;
	uint32 XPlace = (uint32)(Image->GetSizeX() * Coordinates.X);
	uint32 YPlace = (uint32)(Image->GetSizeY() * Coordinates.Y);
	
	PixelColor = FormatedImageData[YPlace * TextureWidth + XPlace];

	RawImageData->Unlock();

	//const float RedValue = PixelColor.R;

	const float alpha = (PixelColor.R / 255.f);


	return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
	
}



UMN_BlendFromImage* UMN_BlendFromImage::ConstructMN_BlendFromImage(UGenerationModule*& MainModule, 
	UGenerationModule*& AddedModule, UTexture2D* Image)
{
	UMN_BlendFromImage* MN_BlendFromImage = NewObject<UMN_BlendFromImage>();
	MN_BlendFromImage->MainModule = MainModule;
	MN_BlendFromImage->AddedModule = AddedModule;
	MN_BlendFromImage->Image = Image;

	return MN_BlendFromImage;
}
