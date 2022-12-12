#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vcclr.h>
#include "FloorSelection.h"
#include "GameController.h"
#include "Floor.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
//using namespace std;

class LoadGame
{


public:
	//  Stores the information for the three saved game states.
	void load(string fileName, FloorSelection* floorSelection, Panel^ drawingPanel, GameController* gameController);
	void showInfo(CheckBox^ load1, CheckBox^ load2, CheckBox^ load3);
	LoadGame() {}

private:
	const int NUMBER_OF_FLOORS = 3;
	const int GAME_INFO_FLAG_INT = 2319;
	const string GAME_INFO_FLAG_STRING = "2319";
};