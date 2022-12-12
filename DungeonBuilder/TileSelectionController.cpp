#include "TileSelectionController.h"
#include "DesignTileDerivedCLasses.h"
#include "TrapTileDerivedClasses.h"
#include "MonsterTileDerivedClasses.h"


TileSelectionController::TileSelectionController(PictureBox^ inImage, RichTextBox^ inDescription)
{
	image = inImage;
	description = inDescription;
}

void TileSelectionController::displaySelectedInfoDesign(int index)
{
	Tile* temp = nullptr;

	// creates new tile based on selected index
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

	// uses created tile to display info to user
	image->Image = temp->getImage();
	String^ text = gcnew String(temp->getDescription().c_str());
	description->Text = text;

	// deletes tile
	delete temp;
}

void TileSelectionController::displaySelectedInfoTraps(int index)
{
	Tile* temp = nullptr;

	// creates new tile based on selected index
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

	// uses created tile to display info to user
	image->Image = temp->getImage();
	String^ text = gcnew String(temp->getDescription().c_str());
	description->Text = text;

	// deletes tile
	delete temp;
}

void TileSelectionController::displaySelectedInfoMonsters(int index)
{
	Tile* temp = nullptr;

	// creates new tile based on selected index
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

	// uses created tile to display info to user
	image->Image = temp->getImage();
	String^ text = gcnew String(temp->getDescription().c_str());
	description->Text = text;

	// deletes tile
	delete temp;
}