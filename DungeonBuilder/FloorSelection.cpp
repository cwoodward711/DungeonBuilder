#include "FloorSelection.h"


FloorSelection::FloorSelection()
{
	this->floorList.push_back(nullptr);
	this->floorList.push_back(nullptr);
	this->floorList.push_back(nullptr);
}

void FloorSelection::createFloor(int floorIndex, Panel^ drawingPanel)
{
	Floor* newFloor = new Floor(floorIndex, drawingPanel, true);
	this->floorList.erase(this->floorList.begin() + floorIndex);
	this->floorList.insert(this->floorList.begin() + floorIndex, newFloor);
}

void FloorSelection::loadFloor(int floorIndex, Panel^ drawingPanel)
{
	if (this->floorList.at(floorIndex) == nullptr)
		createFloor(floorIndex, drawingPanel);
	this->currentFloor = this->floorList.at(floorIndex);
}

void FloorSelection::clearFloors()
{
	if (floorList[0] != nullptr)
	{
		delete floorList[0];
		floorList[0] = nullptr;
	}
	if (floorList[1] != nullptr)
	{
		delete floorList[1];
		floorList[1] = nullptr;
	}
	if (floorList[2] != nullptr)
	{
		delete floorList[2];
		floorList[2] = nullptr;
	}
}

void FloorSelection::updateFloorInfoPanel(int floorIndex, TextBox^ floorInfoNum, Label^ floorManaGen, Label^ floorMonsterNum, Label^ floorTrapNum)
{
	if (this->floorList.at(floorIndex) != nullptr)
	{
		floorInfoNum->Text = "FLOOR " + (this->floorList.at(floorIndex)->getFloorNum() + 1) + " INFO";
		floorManaGen->Text = this->floorList.at(floorIndex)->getFloorManaGen() + "";
		floorMonsterNum->Text = this->floorList.at(floorIndex)->getFloorMonsters() + "";
		floorTrapNum->Text = this->floorList.at(floorIndex)->getFloorTraps() + "";
	}
	else
	{
		floorInfoNum->Text = "FLOOR " + (floorIndex + 1) + " INFO";
		floorManaGen->Text = "0";
		floorMonsterNum->Text = "0";
		floorTrapNum->Text = "0";
	}
}

void FloorSelection::addFloor(int floorIndex, Floor* floor)
{
	this->floorList.erase(this->floorList.begin() + floorIndex);
	this->floorList.insert(this->floorList.begin() + floorIndex, floor);
}

bool FloorSelection::floorsValid()
{
	if (floorList[0] != nullptr && !floorList[0]->isValid())
		return false;
	else if (floorList[1] != nullptr && !floorList[1]->isValid())
		return false;
	else if (floorList[2] != nullptr && !floorList[2]->isValid())
		return false;

	return true;
}

int FloorSelection::getNumOfFloors()
{
	numOfFloors = 0;
	for (int i = 0; i < 3; i++)
	{
		if (floorList[i] != nullptr)
			numOfFloors++;
	}
	return numOfFloors;
}
