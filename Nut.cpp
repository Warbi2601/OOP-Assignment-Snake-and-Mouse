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
	//add score

	//add a message saying "YOU COLLECTED A NUT!" or something

	collected = true;
}
