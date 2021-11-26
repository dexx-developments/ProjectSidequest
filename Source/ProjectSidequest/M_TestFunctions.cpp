// Fill out your copyright notice in the Description page of Project Settings.


#include "M_TestFunctions.h"
UM_TestFunctions::UM_TestFunctions()
{
}


float UM_TestFunctions::ConstructM_TestFunctions(UTexture2D* Image, int32 PixelX, int32 PixelY)
{
	UM_TestFunctions* M_TestFunctions = NewObject<UM_TestFunctions>();
	M_TestFunctions->Image = Image;
	M_TestFunctions->PixelX = PixelX;
	M_TestFunctions->PixelY = PixelY;

	FColor* FormatedImageData = static_cast<FColor*>(Image->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_ONLY));
	FTexture2DMipMap* MyMipMap = &Image->PlatformData->Mips[0];
	int32 TextureWidth = MyMipMap->SizeX, TextureHeight = MyMipMap->SizeY;
	FColor PixelColor;


	if (PixelX >= 0 && PixelX < TextureWidth && PixelY >= 0 && PixelY < TextureHeight)
	{
		PixelColor = FormatedImageData[PixelY * TextureWidth + PixelX];
	}
	Image->PlatformData->Mips[0].BulkData.Unlock();

	return PixelColor.R / 255;

}



FColor UM_TestFunctions::GetPixelData(UTexture2D* Texture, int32 PixelX, int32 PixelY)
{
	UM_TestFunctions* M_TestFunctions = NewObject<UM_TestFunctions>();
	M_TestFunctions->PixelX = PixelX;
	M_TestFunctions->PixelY = PixelY;


	Texture->MipGenSettings.operator=(TMGS_NoMipmaps);
    Texture->SRGB = false;
    Texture->CompressionSettings.operator=(TC_VectorDisplacementmap);
    FTexture2DMipMap* MyMipMap = &Texture->PlatformData->Mips[0];
    FByteBulkData* RawImageData = &MyMipMap->BulkData;
    FColor* FormatedImageData = static_cast<FColor*>(RawImageData->Lock(LOCK_READ_ONLY));
    int32 TextureWidth = MyMipMap->SizeX, TextureHeight = MyMipMap->SizeY;



    FColor PixelColor;

    if (PixelX >= 0 && PixelX < TextureWidth && PixelY >= 0 && PixelY < TextureHeight)
    {
        PixelColor = FormatedImageData[PixelY * TextureWidth + PixelX];
    }

    RawImageData->Unlock();
    return PixelColor;
}