#pragma once
#include "Floor.h"
#include <string>
#include <vcclr.h>
#include <vector>

class FloorSelection
{
	
public:
	FloorSelection();
	
	Floor* getFloor(int floorIndex) { return floorList.at(floorIndex); }

	Floor* getCurrentFloor() { return currentFloor; }

	void loadFloor(int floorIndex, Panel^ drawingPanel);

	void updateFloorInfoPanel(int floorIndex, TextBox^ floorInfoNum, Label^ floorManaGen, Label^ floorMonsterNum, Label^ floorTrapNum );

	void addFloor(int floorIndex, Floor* floor);

	void clearFloors();

	bool floorsValid();

	int getNumOfFloors();

private:
	vector<Floor*> floorList;
	Floor* currentFloor;
	int numOfFloors;

	void createFloor(int floorIndex, Panel^ drawingPanel);
};