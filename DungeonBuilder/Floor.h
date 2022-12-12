#pragma once
#define ROW_TILE_COUNT 10
#define COLUMN_TILE_COUNT 10

#include "Tile.h"
#include <vcclr.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Floor
{
private:
   const int ROW_COUNT = 10;     // number of tiles in row
   const int COLUMN_COUNT = 10;  // number of tiles in column
   const int TILE_SIZE = 56;    // tile dimensions size in pixels
   const int MANA_GEN = 5;

   Tile* tiles[ROW_TILE_COUNT][COLUMN_TILE_COUNT];      // grid of tiles 
   int floorNum;  // the floor number
   int numOfMonsters = 0;
   int numOfTraps = 0;
   int manaSpent = 0;

   gcroot<Panel^> panel; // Panel on which to show floor

   bool hasExit;     // if entrance exists
   bool hasEntrance; // if exit exists 
   bool canEscape;   // if valid path exists from entrance to exit
   char test[ROW_TILE_COUNT][COLUMN_TILE_COUNT]; // test grid tiles to look for valid path

   // contants for test grid  
   static const char OPEN = 'O';    // traversable tile
   static const char DEADEND = '+'; // non traversable tile
   static const char EXIT = 'E';    // exit
   static const char START = 'S';   // entrance
   static const char VISITED = 'X'; // tile already checked

public:
   // constructor
   Floor(int inFloorNum, Panel^ drawingPanel, bool newFloor);

   // destructor
   ~Floor();
   // getters and setters for floor number
   int getFloorNum() { return floorNum; }
   void setFloorNum(int inFloorNum) { floorNum = inFloorNum; }

   // getters
   int getTileSize() { return TILE_SIZE; }
   int getFloorManaSpent() { return manaSpent; }
   int getFloorManaGen() { return MANA_GEN; }
   int getFloorMonsters();// { return numOfMonsters; }
   int getFloorTraps();// { return numOfTraps; }
   int getManaSpent() { return manaSpent; }
   void setManaSpent(int manaSpent) { this->manaSpent += manaSpent; }

   // adds a tile to the floor and returns cost of tile
   int setTile(int tileType, int index, int rowNumber, int columnNumber, int mana);

   // removes a tile from the floor
   int removeTile(int rowNumber, int columnNumber);

   // displays the floor for the user to see
   void drawFloor();

   // returns true/false if a valid path exists from entrance to exit
   bool isValid();

   // returns true/false whether the respective tiles exist
   bool hasAnEntrance() { return hasEntrance; }
   bool hasAnExit() { return hasExit; }

   int getTileID(int x_pos, int y_pos) { return tiles[x_pos][y_pos]->getTileID(); }

   Tile* getTile(int x_pos, int y_pos) { return tiles[x_pos][y_pos]; }
   void loadTile(int x_pos, int y_pos, int tileID);

private:
   // recursively checks to see if valid floor
   void Floor::RecSolve(int row, int col);

   // creates and returns tile of type Design
   Tile* createDesignTile(int index);

   // creates and returns tile of type Traps
   Tile* createTrapsTile(int index);

   // creates and returns tile of type Monsters
   Tile* createMonstersTile(int index);
   
   Tile* createTile(int tileID);
};