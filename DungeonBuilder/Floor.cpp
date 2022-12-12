#include "Floor.h"
#include "DesignTileDerivedClasses.h"
#include "TrapTileDerivedClasses.h"
#include "MonsterTileDerivedClasses.h"

Floor::Floor(int inFloorNum, Panel^ drawingPanel, bool newFloor)
{
   floorNum = inFloorNum;
   panel = drawingPanel;

	// intializes all grid locations
   for (int i = 0; i < ROW_COUNT; i++)
      for (int j = 0; j < COLUMN_COUNT; j++)
         tiles[i][j] = nullptr;

	// places original entrance, exit, and path between them
   if (newFloor)
   {
	   setTile(1, 1, 1, 0, 99);
	   setTile(1, 0, 8, 9, 99);
	   setTile(1, 2, 1, 1, 99);
	   setTile(1, 2, 1, 2, 99);
	   setTile(1, 2, 1, 3, 99);
	   setTile(1, 2, 2, 3, 99);
	   setTile(1, 2, 3, 3, 99);
	   setTile(1, 2, 4, 3, 99);
	   setTile(1, 2, 5, 3, 99);
	   setTile(1, 2, 5, 4, 99);
	   setTile(1, 2, 5, 5, 99);
	   setTile(1, 2, 5, 6, 99);
	   setTile(1, 2, 5, 7, 99);
	   setTile(1, 2, 6, 7, 99);
	   setTile(1, 2, 7, 7, 99);
	   setTile(1, 2, 8, 7, 99);
	   setTile(1, 2, 8, 8, 99);
   }
	hasExit = true;
	hasEntrance = true;
}

Floor::~Floor()
{
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COLUMN_COUNT; j++)
		{
			if (tiles[i][j] == nullptr)
				delete tiles[i][j];
		}
	}
}

int Floor::setTile(int tileType, int index, int rowNumber, int columnNumber, int mana)
{
	Tile* temp = nullptr;
	// creates and adds tile to desired location
	if (tileType == 1)
		temp = createDesignTile(index);
	else if (tileType == 2)
		temp = createTrapsTile(index);
	else
		temp = createMonstersTile(index);

	int cost = 0;

	// if too expensive
	if(tiles[rowNumber][columnNumber] != nullptr && (temp->getPrice() - tiles[rowNumber][columnNumber]->getPrice() > mana))
	{ 
		delete temp;
		return -10;
	}
	else if (temp->getPrice() > mana)
	{
		delete temp;
		return -10;
	}
	else
	{
		if (tiles[rowNumber][columnNumber] != nullptr)
		{
			cost -= tiles[rowNumber][columnNumber]->getPrice();
			if (tiles[rowNumber][columnNumber]->getTileType() == 1 && tiles[rowNumber][columnNumber]->getTileTypeIndex() == 0)
				hasEntrance = false;
			else if (tiles[rowNumber][columnNumber]->getTileType() == 1 && tiles[rowNumber][columnNumber]->getTileTypeIndex() == 1)
				hasExit = false;
			delete tiles[rowNumber][columnNumber];
		}
		tiles[rowNumber][columnNumber] = temp;
		cost += tiles[rowNumber][columnNumber]->getPrice();
		//manaSpent += cost;
	}
	
	// if tile placed is entrance or exit
	if (tiles[rowNumber][columnNumber]->getTileType() == 1 && index == 0)
		hasEntrance = true;
	else if (tiles[rowNumber][columnNumber]->getTileType() == 1 && index == 1)
		hasExit = true;

	panel->Invalidate();
	return cost;
	return -10;
}

int Floor::removeTile(int rowNumber, int columnNumber)
{
	int costRefund = 0;
	if (tiles[rowNumber][columnNumber] != nullptr)
	{
		costRefund = tiles[rowNumber][columnNumber]->getPrice();
		
		if (tiles[rowNumber][columnNumber]->getTileType() == 1 && tiles[rowNumber][columnNumber]->getTileTypeIndex() == 0)
			hasEntrance = false;
		else if (tiles[rowNumber][columnNumber]->getTileType() == 1 && tiles[rowNumber][columnNumber]->getTileTypeIndex() == 1)
			hasExit = false;
			
		delete tiles[rowNumber][columnNumber];
		tiles[rowNumber][columnNumber] = nullptr;
	}
	//causes paint event
	panel->Invalidate();
	//manaSpent -= costRefund;
	return costRefund;
}

void Floor::drawFloor()
{
	// draws all placed tiles
	Graphics^ g = panel->CreateGraphics();
   for (int i = 0; i < ROW_COUNT; i++)
		for (int j = 0; j < COLUMN_COUNT; j++)
		{
			if(tiles[i][j] != nullptr)
				g->DrawImageUnscaled(tiles[i][j]->getImage(), i * TILE_SIZE, j * TILE_SIZE);
		}

   // draws gridlines on dungeon floor
   Graphics^ canvasGraphics = panel->CreateGraphics();
   Color color;
   for (int i = 0; i <= ROW_COUNT; i++)
      canvasGraphics->FillRectangle(gcnew SolidBrush(color.FromArgb(90, 255, 255, 255)), i * TILE_SIZE, 0, 1, panel->Height);
   for (int i = 0; i <= COLUMN_COUNT; i++)
      canvasGraphics->FillRectangle(gcnew SolidBrush(color.FromArgb(90, 255, 255, 255)), 0, i * TILE_SIZE, panel->Width, 1);
   canvasGraphics->FillRectangle(gcnew SolidBrush(color.FromArgb(90, 255, 255, 255)), panel->Width - 3, 0, 1, panel->Height);
   canvasGraphics->FillRectangle(gcnew SolidBrush(color.FromArgb(90, 255, 255, 255)), 0, panel->Height - 2, panel->Width, 1);
}

void Floor::loadTile(int x_pos, int y_pos, int tileID)
{
	// creates and adds tile to desired location
	tiles[x_pos][y_pos] = createTile(tileID);

	//panel->Invalidate();

}

bool Floor::isValid()
{
	// not valid if exit or entrance missing
	if(!hasAnExit() || !hasAnEntrance())
		return false;

	canEscape = false;
	int startX = 0, startY = 0;

	// loops through and initializes test grid to test if floor is valid
	for(int i = 0; i < ROW_TILE_COUNT; i++)
		for (int j = 0; j < COLUMN_TILE_COUNT; j++)
		{
			if (tiles[i][j] == nullptr)
				test[i][j] = DEADEND;
			// in case of tile being the entrance
			else if (tiles[i][j]->getTileType() == 1 && tiles[i][j]->getTileTypeIndex() == 0)
			{
				test[i][j] = OPEN;
				startX = i;
				startY = j;
			}
			else if (tiles[i][j]->getTileType() == 1 && tiles[i][j]->getTileTypeIndex() == 1)
				test[i][j] = EXIT;
			else
				test[i][j] = OPEN;
		}
	// resursively attempt to find escape path
	RecSolve(startX, startY);
	return canEscape;
}

void Floor::RecSolve(int row, int col)
{
	// Base casse. Off grid
	if (row < 0 || row >= ROW_TILE_COUNT || col < 0 || col >= COLUMN_TILE_COUNT)
		return;
	// Base case. Exit found
	if (test[row][col] == EXIT)
	{
		canEscape = true;
		return;
	}
	// Base case. Not traversable tile
	if (test[row][col] == DEADEND || test[row][col] == VISITED)
		return;

	// Marks current tile
	test[row][col] = VISITED;

	// Recursive case. Checks all adjacent tiles
	RecSolve(row - 1, col);
	RecSolve(row + 1, col);
	RecSolve(row, col - 1);
	RecSolve(row, col + 1);
}


Tile* Floor::createDesignTile(int index)
{
	Tile* temp = nullptr;

	// creates tile based on selected index
	switch (index)
	{
	case 0:
		temp = new Entrance();
		break;
	case 1:
		temp = new ExitDoor();
		break;
	case 2:
		temp = new Path();
		break;
	case 3:
		temp = new Door();
		break;
	case 4:
		temp = new TreasureChest();
		break; 
	}
	return temp;
}


Tile* Floor::createTrapsTile(int index)
{
	Tile* temp = nullptr;

	// creates tile based on selected index
	switch (index)
	{
	case 0:
		temp = new Tripwire();
		break;
	case 1:
		temp = new Pitfall();
		break;
	case 2:
		temp = new Spikes();
		break;
	}
	numOfTraps++;
	return temp;
}


Tile* Floor::createMonstersTile(int index)
{
	Tile* temp = nullptr;

	// creates tile based on selected index
	switch (index)
	{
	case 0:
		temp = new Goblin();
		break;
	case 1:
		temp = new Orc();
		break;
	case 2:
		temp = new Ogre();
		break;
	}
	numOfMonsters++;
	return temp;
}

Tile* Floor::createTile(int tileID)
{
	Tile* temp = nullptr;
	switch (tileID)
	{
	case 0:
		temp = new Door();
		break;
	case 1:
		temp = new ExitDoor();
		break;
	case 2:
		temp = new Path();
		break;
	case 3:
		temp = new Entrance();
		break;
	case 4:
		temp = new TreasureChest();
		break;
	case 5:
		temp = new Tripwire();
		numOfTraps++;
		break;
	case 6:
		temp = new Pitfall();
		numOfTraps++;
		break;
	case 7:
		temp = new Spikes();
		numOfTraps++;
		break;
	case 8:
		temp = new Goblin();
		numOfMonsters++;
		break;
	case 9:
		temp = new Orc();
		numOfMonsters++;
		break;
	case 10:
		temp = new Ogre();
		numOfMonsters++;
		break;
		
	}	
	return temp;
}

int Floor::getFloorMonsters()
{
	int count = 0;
	for (int i = 0; i < ROW_TILE_COUNT; i++)
		for (int j = 0; j < COLUMN_TILE_COUNT; j++)
			if (tiles[i][j] != nullptr && tiles[i][j]->getTileType() == 3)
				count++;
	return count;
}

int Floor::getFloorTraps()
{
	int count = 0;
	for (int i = 0; i < ROW_TILE_COUNT; i++)
		for (int j = 0; j < COLUMN_TILE_COUNT; j++)
			if (tiles[i][j] != nullptr && tiles[i][j]->getTileType() == 2)
				count++;
	return count;
}