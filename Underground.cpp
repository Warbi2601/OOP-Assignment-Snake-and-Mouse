#include "Underground.h"

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

bool Underground::has_reached_a_hole(Mouse& mouse) const
{
	for (int h_no(0); h_no < holes_.size(); ++h_no)
	{
		Hole h = get_hole_no(h_no);

		if (mouse.is_at_position(h.get_x(), h.get_y()))
		{
			return true;
		}
	}
	return false;
}

vector<Hole> Underground::getHoles() const
{
	return holes_;
}

void Underground::get_random_hole_for_mouse(Mouse& mouse) const
{
	bool validHole = false;
	while (!validHole)
	{
		int rnd = rand() % holes_.size();
		Hole h = get_hole_no(rnd);
		if (!mouse.is_at_position(h.get_x(), h.get_y()))
		{
			mouse.set_x(h.get_x());
			mouse.set_y(h.get_y());
			validHole = true;
		}
	}
}

