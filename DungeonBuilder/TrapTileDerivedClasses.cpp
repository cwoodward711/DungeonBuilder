#include "TrapTileDerivedClasses.h"

Tripwire::Tripwire() : TrapTile(1, "Might sprain an ankle, might alert the horde of angry goblins around the corner.")
{
	image = gcnew Drawing::Bitmap("Tripwire.bmp");
	tileTypeIndex = 0;
	tileID = 5;
}

Pitfall::Pitfall() : TrapTile(2, "Break a leg... or a skull.")
{
	image = gcnew Drawing::Bitmap("Pitfall.bmp");
	tileTypeIndex = 1;
	tileID = 6;
}

Spikes::Spikes() : TrapTile(3, "Did someone say shish kebab?")
{
	image = gcnew Drawing::Bitmap("SpikeTrap.bmp");
	tileTypeIndex = 2;
	tileID = 7;
}
