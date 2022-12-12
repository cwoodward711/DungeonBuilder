#pragma once
#include "DesignTile.h"

class Door : public DesignTile
{
public:
   Door();
};

class ExitDoor : public DesignTile
{
public:
   ExitDoor();
};

class Path : public DesignTile
{
public:
	Path();
};

class Entrance : public DesignTile
{
public:
   Entrance();
};


class TreasureChest : public DesignTile
{
public:
   TreasureChest();
};