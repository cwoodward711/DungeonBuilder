#include "SaveGame.h"

void SaveGame::save(string fileName, System::String^ biome, FloorSelection* floorSelection, GameController* gameController)
{
	time_t current_time = time(0);

	// Gets a string of the time and date
	char* dt = ctime(&current_time);
	// Creates the file
	ofstream saveFile(fileName);
	saveFile << dt << endl;
	//saveFile << biome->ToString();
	for (int k = 0; k < NUMBER_OF_FLOORS; k++)
	{
		if (floorSelection->getFloor(k) != nullptr)
		{
			saveFile << k << endl;
			Floor* floor = floorSelection->getFloor(k);
			for (int i = 0; i < ROW_TILE_COUNT; i++)
			{
				for (int j = 0; j < COLUMN_TILE_COUNT; j++)
				{
					if (floor->getTile(i, j) != nullptr)
					{
						saveFile << floor->getTileID(i, j) << " ";
					}
					else
						saveFile << "-1 ";
				}
				saveFile << endl;
			}
		}	
	}
	saveFile << GAME_INFO_FLAG << endl;
	saveFile << gameController->getBiome() << endl << floorSelection->getNumOfFloors() << endl << gameController->getTurn() << endl;
	saveFile << gameController->getMana() << endl;
}