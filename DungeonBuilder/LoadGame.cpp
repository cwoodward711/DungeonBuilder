#include "LoadGame.h"

void LoadGame::load(string fileName, FloorSelection* floorSelection, Panel^ drawingPanel, GameController* gameController)
{
	int tileID;
	int floorInfo;
	string firstLine;
	floorSelection->clearFloors();
	// Load the file
	ifstream loadFile(fileName);
	getline(loadFile, firstLine);
	while (loadFile >> floorInfo && floorInfo != GAME_INFO_FLAG_INT)
	{
		Floor* floor = new Floor(floorInfo, drawingPanel, false);
		for (int i = 0; i < ROW_TILE_COUNT; i++)
		{
			for (int j = 0; j < COLUMN_TILE_COUNT; j++)
			{
				loadFile >> tileID;
				if (tileID != -1)
					floor->loadTile(i, j, tileID);
			}
		}
		floorSelection->addFloor(floorInfo, floor);
	}
	loadFile >> floorInfo;
	gameController->setBiome(floorInfo);
	loadFile >> floorInfo >> floorInfo;
	gameController->setTurn(floorInfo);
	loadFile >> floorInfo;
	gameController->setMana(floorInfo);
	
}

void LoadGame::showInfo(CheckBox^ load1, CheckBox^ load2, CheckBox^ load3)
{
	string floorInfo;
	string totalInfo;
	System::String^ inputInfo;
	ifstream loadFile;
	loadFile.open("save1.txt");
	if (loadFile)
	{
		getline(loadFile, floorInfo);
		totalInfo = totalInfo + floorInfo + "\n";
		getline(loadFile, floorInfo);
		while (loadFile >> floorInfo)
		{
			if (floorInfo == GAME_INFO_FLAG_STRING)
			{
				int i = 0;
				while (loadFile >> floorInfo)
				{
					if (i == 0)
						totalInfo = totalInfo + "Biome: " + floorInfo + "\n";
					else if (i == 1)
						totalInfo = totalInfo + "# of Floors: " + floorInfo + "\n";
					else if (i == 2)
						totalInfo = totalInfo + "# of Turns: " + floorInfo + "\n";
					i++;
				}
			}
		}
		inputInfo = gcnew String(totalInfo.c_str());
		load1->Text = inputInfo;
		inputInfo->Empty;
		totalInfo.erase();
	}
	else
		load1->Text = "EMPTY";
	
	loadFile.close();
	loadFile.open("save2.txt");
	if (loadFile)
	{
		getline(loadFile, floorInfo);
		totalInfo = totalInfo + floorInfo + "\n";
		getline(loadFile, floorInfo);
		while (loadFile >> floorInfo)
		{
			if (floorInfo == GAME_INFO_FLAG_STRING)
			{
				int i = 0;
				while (loadFile >> floorInfo)
				{
					if (i == 0)
						totalInfo = totalInfo + "Biome: " + floorInfo + "\n";
					else if (i == 1)
						totalInfo = totalInfo + "# of Floors: " + floorInfo + "\n";
					else if (i == 2)
						totalInfo = totalInfo + "# of Turns: " + floorInfo + "\n";
					i++;
				}
			}
		}
		inputInfo = gcnew String(totalInfo.c_str());
		load2->Text = inputInfo;
		inputInfo->Empty;
		totalInfo.erase();
	}
	else
		load2->Text = "EMPTY";

	loadFile.close();
	loadFile.open("save3.txt");
	if (loadFile)
	{
		getline(loadFile, floorInfo);
		totalInfo = totalInfo + floorInfo + "\n";
		getline(loadFile, floorInfo);
		while (loadFile >> floorInfo)
		{
			if (floorInfo == GAME_INFO_FLAG_STRING)
			{
				int i = 0;
				while (loadFile >> floorInfo)
				{
					if (i == 0)
						totalInfo = totalInfo + "Biome: " + floorInfo + "\n";
					else if (i == 1)
						totalInfo = totalInfo + "# of Floors: " + floorInfo + "\n";
					else if (i == 2)
						totalInfo = totalInfo + "# of Turns: " + floorInfo + "\n";
					i++;
				}
			}
		}
		inputInfo = gcnew String(totalInfo.c_str());
		load3->Text = inputInfo;
		inputInfo->Empty;
		totalInfo.erase();
	}
	else
		load3->Text = "EMPTY";
	loadFile.close();
}