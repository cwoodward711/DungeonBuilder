#pragma once

#include <vcclr.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class GameController
{
private:
   const int maxMana = 20; // max mana player can hold
   int manaIncrement = 5;  // how much mana player gains per turn

   int mana;    // current mana amount player has
   int turnNum; // current turn number
   int biome;   // biome selected by player
   int numOfFloors; //the number of created floors

   gcroot<Label^> turnNumber;
   gcroot<Label^> manaAmount;

public:
   // constructor
   GameController(Label^ inTurnNumber, Label^ inManaAmount);
   
   // sets the biome
   void setBiome(int inBiome) { biome = inBiome; }

   // gets the biome 
   int getBiome() { return biome; }

   // gets current mana amount
   int getMana() { return mana; }
   void setMana(int mana);

   // subtracts cost of placed tile
   void spendMana(int cost);

   // adds mana gained from killing enemies or removing placed tiles
   void manaGain(int amount);

   // ends turn
   void endTurn();

   int getTurn() { return turnNum; }
   void setTurn(int turnNum);
};