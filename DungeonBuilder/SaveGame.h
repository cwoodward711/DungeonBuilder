#pragma once
#include <ctime>
#include <iostream>
#include <fstream>
#include <vcclr.h>
#include "FloorSelection.h"
#include "GameController.h"
#include "Floor.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class SaveGame
{

public:
	//  Stores the information for the three saved game states.
	void save(string fileName, System::String^ biome, FloorSelection* floorSelection,
		GameController* gameController);
	SaveGame() {}

private:
	const int NUMBER_OF_FLOORS = 3;
	const int GAME_INFO_FLAG = 2319;
};