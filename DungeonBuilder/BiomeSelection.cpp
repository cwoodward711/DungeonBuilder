#include "BiomeSelection.h"


int BiomeSelection::loadBiome(Color color)
{
	Color inColor = Color::FromArgb(color.ToArgb());
	Color colorForest = Color::FromArgb(255, 41, 188, 86);
	Color colorDesert = Color::FromArgb(255, 251, 231, 159);
	Color colorMountains = Color::FromArgb(255, 148, 148, 148);
	if (inColor == colorForest)
	{
		biomeID = 1;
		return 1;
	}
	else if (inColor == colorDesert)
	{
		biomeID = 0;
		return 0;
	}
	else if (inColor == colorMountains)
	{
		biomeID = 2;
		return 2;
	}
	else
		MessageBox::Show("Biome not yet implemented, try another location!");
}

System::String^ BiomeSelection::createBiome(int biome, PictureBox^ floorSelectionBG, Label^ floorType, Label^ bossName, PictureBox^ FloorScreenBG)
{
	System::String^ floorEditorBiome;
	if (biome == 0)
	{
		floorSelectionBG->Image = gcnew Bitmap("DesertBackground.bmp");
		FloorScreenBG->Image = gcnew Bitmap("DesertBackground.bmp");

		floorEditorBiome = "DESERT";
		floorType->Text = "Sand Dunes";
		bossName->Text = "Lenny the Sandworm";
	}
	else if (biome == 1)
	{
		floorSelectionBG->Image = gcnew Bitmap("ForestBackground.bmp");
		FloorScreenBG->Image = gcnew Bitmap("ForestBackground.bmp");
		floorEditorBiome = "FOREST";
		floorType->Text = "Forest Floor";
		bossName->Text = "Treebeard the Ent";
	}
	else if (biome == 2)
	{
		floorSelectionBG->Image = gcnew Bitmap("MountainBackground.bmp");
		FloorScreenBG->Image = gcnew Bitmap("MountainBackground.bmp");
		floorEditorBiome = "MOUNTAIN";
		floorType->Text = "Mountainous";
		bossName->Text = "Smaug the Dragon";
	}
	return floorEditorBiome;
}