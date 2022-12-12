#include "DesignTileDerivedClasses.h"


Door::Door() : DesignTile(2, "For entering and exiting inner rooms.")
{
   image = gcnew Drawing::Bitmap("Door.bmp");
   tileTypeIndex = 3;
   tileID = 0;
}

ExitDoor::ExitDoor() : DesignTile(0, "Exit a floor through this door.")
{
   image = gcnew Drawing::Bitmap("Exit.bmp");
   tileTypeIndex = 1;
   tileID = 1;
}

Path::Path() : DesignTile(1, "Make them go in circles.")
{
	image = gcnew Drawing::Bitmap("Path.bmp");
   tileTypeIndex = 2;
   tileID = 2;
}

Entrance::Entrance() : DesignTile(0, "Watch out for wandering enemies!")
{
   image = gcnew Drawing::Bitmap("Entrance.bmp");
   tileTypeIndex = 0;
   tileID = 3;
}

TreasureChest::TreasureChest() : DesignTile(3, "Could be gold, could be a mimic. You'll have to open it to find out.")
{
   image = gcnew Drawing::Bitmap("Chest.bmp");
   tileTypeIndex = 4;
   tileID = 4;
}
