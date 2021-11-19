// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#include "MN_Testing1.h"

UMN_Testing1::UMN_Testing1()
{
}

float UMN_Testing1::GetValue(const FVector& Coordinates) const
{
	/* const int ix = FMath::FloorToInt(Coordinates.X * StartX);
	const int iy = FMath::FloorToInt(Coordinates.Y * StartX);
	const int iz = FMath::FloorToInt(Coordinates.Z * StartX);

	return _moduleA->GetValue(Coordinates) + _moduleB->GetValue(Coordinates);
	*/

	if (Coordinates.X >= BlendStartX && Coordinates.X <= BlendEndX) { //Innanf�r X blend
		if (Coordinates.Y >= BlendStartY && Coordinates.Y <= BlendEndY) { //Innanf�r X och Y blend
			if (Coordinates.X >= StartX && Coordinates.X <= EndX) { // Innanf�r X
				if (Coordinates.Y >= StartY && Coordinates.Y <= EndY) { //Innanf�r X och Y
					return AddedModule->GetValue(Coordinates);
				}
				else {
					if (Coordinates.Y <= EndY) { //cY �r mindre �n startY men mer �n BlendStartY
						const float alpha = (1.f - (StartY - Coordinates.Y) / (StartY - BlendStartY));
						return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
					}
					else { //Y �r mer �n EndY men mindre �n BlendEndY
						const float alpha = (1.f - (Coordinates.Y - EndY) / (BlendEndY - EndY));
						return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
					}
				}
			}
			else {
				if (Coordinates.Y >= StartY && Coordinates.Y <= EndY) { //Innanf�r X blend, och i Y
					if (Coordinates.X <= EndX) { //cX �r mindre �n startX men mer �n BlendStartX
						const float alpha = (1.f - (StartX - Coordinates.X) / (StartX - BlendStartX));
						return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
					}
					else { //X �r mer �n EndX men mindre �n BlendEndX
						const float alpha = (1.f - (Coordinates.X - EndX) / (BlendEndX - EndX));
						return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
					}
				}
				else { //Innanf�r X och Y blend
					if (Coordinates.X <= EndX) { //cX �r i blendstartX till startX
						if (Coordinates.Y <= EndY) { //cY �r i blendstartY till StartY
							if ((StartY - Coordinates.Y) / (StartY - BlendStartY) > (StartX - Coordinates.X) / (StartX - BlendStartX)) {
								const float alpha = (1.f - ((StartY - Coordinates.Y) / (StartY - BlendStartY)));
								return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
							}
							else {
								
								const float alpha = (1.f - ((StartX - Coordinates.X) / (StartX - BlendStartX)));
								return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
							}
						}
						else { //Y �r i EndY till BlendEndY
							if ((Coordinates.Y - EndY) / (BlendEndY - EndY) > (StartX - Coordinates.X) / (StartX - BlendStartX)) {
								const float alpha = (1.f - ((Coordinates.Y - EndY) / (BlendEndY - EndY)));
								return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
							}
							else {
								const float alpha = (1.f - ((StartX - Coordinates.X) / (StartX - BlendStartX)));
								return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
							}
						}
					}
					else { //Y �r mer �n EndY men mindre �n BlendEndY
						if (Coordinates.Y <= EndY) { //cY �r i blendstartY till StartY
							if ((StartY - Coordinates.Y) / (StartY - BlendStartY) > (Coordinates.X - EndX) / (BlendEndX - EndX)) {
								const float alpha = (1.f - (StartY - Coordinates.Y) / (StartY - BlendStartY));
								return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
							}
							else {
								const float alpha = (1.f - (Coordinates.X - EndX) / (BlendEndX - EndX));
								return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
							}
						}
						else { //Y �r i EndY till BlendEndY
							if ((Coordinates.Y - EndY) / (BlendEndY - EndY) > (Coordinates.X - EndX) / (BlendEndX - EndX)){
								const float alpha = (1.f - (Coordinates.Y - EndY) / (BlendEndY - EndY));
								return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
							}
							else {
								const float alpha = (1.f - (Coordinates.X - EndX) / (BlendEndX - EndX));
								return FMath::Lerp(MainModule->GetValue(Coordinates), AddedModule->GetValue(Coordinates), alpha);
							}
						}
					}

					//return MainModule->GetValue(Coordinates);

				}
			}
		}


		else {
			return MainModule->GetValue(Coordinates);
		}
	}
	else {
		return MainModule->GetValue(Coordinates);
	}


	if (Coordinates.X <= StartX || Coordinates.X >= EndX) {
		return MainModule->GetValue(Coordinates);
	}
	else {
		if (Coordinates.Y <= StartY || Coordinates.Y >= EndY) {
			return MainModule->GetValue(Coordinates);
		}
		else {
			return AddedModule->GetValue(Coordinates);
		}
	}
}

/** I'm mad
* If Coordinates.X <= StartX <= BlendStartX s� blir det MainModule
* Else if Coordinates.X <= StartX >= BlendStartX s� blir det en graduell blandning mellan Main o Added
* Else if Coordinates.X >= StartX >= BlendStartX s� blir det added
* Coordinates.X <= StartX >= BlendStartX 
return FMath::Sin((Coordinates.X * XFrequency + Coordinates.Y * YFrequency) * PI); **/

UMN_Testing1* UMN_Testing1::ConstructMN_Testing1(UGenerationModule*& MainModule, UGenerationModule*& AddedModule,	
	const float StartX, const float BlendStartX, const float EndX, const float BlendEndX, const float StartY, 
	const float BlendStartY, const float EndY, const float BlendEndY)
{
	UMN_Testing1* MN_Testing1 = NewObject<UMN_Testing1>();
	MN_Testing1->MainModule = MainModule;
	MN_Testing1->AddedModule = AddedModule;
	MN_Testing1->StartX = StartX;
	MN_Testing1->BlendStartX = BlendStartX;
	MN_Testing1->EndX = EndX;
	MN_Testing1->BlendEndX = BlendEndX;
	MN_Testing1->StartY = StartY;
	MN_Testing1->BlendStartY = BlendStartY;
	MN_Testing1->EndY = EndY;
	MN_Testing1->BlendEndY = BlendEndY;
	return MN_Testing1;
}
