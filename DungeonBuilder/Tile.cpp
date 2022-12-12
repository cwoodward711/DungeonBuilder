#include "Tile.h"

Tile::Tile()
{
   // default values. Will never be used
   price = 0;
   tileType = -1;
   description = "";
}

Tile::Tile(int inPrice, int inTileType, string inDescription)
{
   price = inPrice;
   tileType = inTileType;
   description = inDescription;
}
