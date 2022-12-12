#include "MonsterTileDerivedClasses.h"

Goblin::Goblin() : MonsterTile(1, "Small and stupid, but dangerous in numbers.")
{
	image = gcnew Drawing::Bitmap("Goblins.bmp");
	tileTypeIndex = 0;
	tileID = 8;
}

Orc::Orc() : MonsterTile(2, "Smart but prone to bouts of rage.")
{
	image = gcnew Drawing::Bitmap("Orc.bmp");
	tileTypeIndex = 1;
	tileID = 9;
}

Ogre::Ogre() : MonsterTile(3, "OGRE SMASH!")
{
	image = gcnew Drawing::Bitmap("Ogre.bmp");
	tileTypeIndex = 2;
	tileID = 10;
}
