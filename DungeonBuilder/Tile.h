#pragma once
#include <string>
#include <vcclr.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace std;

class Tile
{
protected:
   int price;                      // cost in mana
   int tileType;                   // type of tile
   int tileID;					   // tile idenifier
   int tileTypeIndex;              // index of tileType
   string description;             // describes the tile
   gcroot<Drawing::Bitmap^> image; // tile image

public:
   // default constructor
   Tile();

   // paramterized constructor
   Tile(int inPrice, int inTileType, string inDescription);

   // getters & Setters for price
   int getPrice() { return price; }
   void setPrice(int inPrice) { price = inPrice; }

   // getters & setters for tileType
   int getTileType() { return tileType; }
   void setTileType(int inTileType) { tileType = inTileType; }

   // getters & setters for tileTypeIndex
   int getTileTypeIndex() { return tileTypeIndex; }
   void getTileTypeIndex(int inTileTypeIndex) { tileTypeIndex = inTileTypeIndex; }

   // getters & setters for description
   string getDescription() { return description; }
   void setDescription(string inDescription) { description = inDescription; }

   // getter for tile ID
   int getTileID() { return tileID; }

   // getter for image
   gcroot<Drawing::Bitmap^> getImage() { return image; }
};