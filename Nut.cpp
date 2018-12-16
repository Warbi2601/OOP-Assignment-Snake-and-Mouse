#include "Nut.h"

using namespace std;

Nut::Nut(int setX, int setY) : FixedGridItem(NUT, setX, setY)
{

}

bool Nut::has_been_collected()
{
	return collected;
}

void Nut::collect_nut()
{
	collected = true;
}

void Nut::reset_nut()
{
	this->collected = false;
}
