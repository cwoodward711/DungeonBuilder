#pragma once
using namespace System::Drawing;
using namespace System::Windows::Forms;
class BiomeSelection
{

public:
	int biomeID = -1;
	BiomeSelection() {}
	int loadBiome(Color);
	System::String^ BiomeSelection::createBiome(int biome, PictureBox^ floorSelectionBG, Label^ floorType, Label^ bossName, PictureBox^ FloorScreenBG);

};