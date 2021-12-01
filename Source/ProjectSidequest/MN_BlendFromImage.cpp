// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/Color.h"
#include "MN_BlendFromImage.h"

UMN_BlendFromImage::UMN_BlendFromImage()
{
}

float UMN_BlendFromImage::GetValue(const FVector& Coordinates) const
{

	//Fixes image for RGB reading
	Image->MipGenSettings.operator=(TMGS_NoMipmaps);
	Image->SRGB = false;
	Image->CompressionSettings.operator=(TC_VectorDisplacementmap);
	FTexture2DMipMap* MyMipMap = &Image->PlatformData->Mips[0];
	FByteBulkData* RawImageData = &MyMipMap->BulkData;
	FColor* FormatedImageData = static_cast<FColor*>(RawImageData->Lock(LOCK_READ_ONLY));
	FColor PixelColor;
	int32 TextureWidth = MyMipMap->SizeX, TextureHeight = MyMipMap->SizeY;
	int32 XPlace = 0, YPlace = 0;


	if (LoopTiles == false)
	{
		XPlace = (int32)(TextureWidth * Coordinates.X / TileCountX);
		YPlace = (int32)(TextureHeight * Coordinates.Y / TileCountY);
	}else
	{
		XPlace = (int32)(TextureWidth * (Coordinates.X - (int32)Coordinates.X));
		YPlace = (int32)(TextureHeight * (Coordinates.Y - (int32)Coordinates.Y));
	}

	if (XPlace > TextureWidth)
	{
		XPlace = TextureWidth;
	}
	else if (XPlace < 0)
	{
		XPlace = 0;
	}
	else if (YPlace > TextureHeight)
	{
		YPlace = TextureHeight;
	}
	else if (YPlace < 0)
	{
		YPlace = 0;
	}
	
	PixelColor = FormatedImageData[YPlace * TextureWidth + XPlace];

	RawImageData->Unlock();

	const float alpha = (PixelColor.R / 255.f);

	return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
}



UMN_BlendFromImage* UMN_BlendFromImage::ConstructMN_BlendFromImage(UGenerationModule*& MainModule, 
	UGenerationModule*& AddedModule, UTexture2D* Image, int32 TileCountX, int32 TileCountY, bool LoopTiles)
{
	UMN_BlendFromImage* MN_BlendFromImage = NewObject<UMN_BlendFromImage>();
	MN_BlendFromImage->MainModule = MainModule;
	MN_BlendFromImage->AddedModule = AddedModule;
	MN_BlendFromImage->Image = Image;
	MN_BlendFromImage->TileCountX = TileCountX;
	MN_BlendFromImage->TileCountY = TileCountY;
	MN_BlendFromImage->LoopTiles = LoopTiles;

	return MN_BlendFromImage;
}
