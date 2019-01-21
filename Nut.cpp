#include "Nut.h"

using namespace std;

// Nut currently inherits FixedGridItem for the basic version,
// As it is added to the grid at a predefined location.
//
// This will be updated to MoveableGridItem for the extended version,
// As it becomes pushable.
Nut::Nut(int setX, int setY) : FixedGridItem(NUT, setX, setY)
{
	// Extended version
	// position_at_random();
}

bool Nut::has_been_collected()
{
	return collected;
}

void Nut::collect_nut()
{
	collected = true;
}

void Nut::set_nut(bool collected) 
{
	this->collected = collected;
}

void Nut::reset_nut()
{
	this->collected = false;
}
