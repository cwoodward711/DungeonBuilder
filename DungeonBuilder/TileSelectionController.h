#pragma once
#include "Tile.h"
#include <vcclr.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class TileSelectionController
{
private:
   gcroot<PictureBox^> image;          // picture box when tile selected
   gcroot<RichTextBox^> description;   // description text box when tile selected

public:
   // constructor
   TileSelectionController(PictureBox^ inImage, RichTextBox^ inDescription);

   // displays info for selected design tile
   void displaySelectedInfoDesign(int index);

   // displays info for slected traps tile
   void displaySelectedInfoTraps(int index);

   // displays info for selected monsters tile
   void displaySelectedInfoMonsters(int index);
};