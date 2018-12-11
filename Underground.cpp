#include "Underground.h"

Hole::Hole() : FixedGridItem(HOLE, 0, 0)
{

}

Hole::Hole(int x, int y) : FixedGridItem(HOLE, x, y)
{
}

// number of holes in underground
const int MAXHOLES(3);

Underground::Underground() : holes_({ Hole(4, 3), Hole(15, 10), Hole(7, 15) })
{

}

Hole Underground::get_hole_no(int no) const
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	return holes_.at(no);
}

/* void Underground::set_hole_no_at_position(int no, int x, int y)
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	Hole h(x, y);

	holes_.at(no) = h;
} */

bool Underground::is_valid_hole_number(int no) const
{
	return (no >= 0) && (no < holes_.size());
}