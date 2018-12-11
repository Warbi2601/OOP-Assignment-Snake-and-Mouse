#include "Mouse.h"

Mouse::Mouse() : MoveableGridItem(MOUSE, 0, 0), alive_(true), escaped_(false), mouse_dx_(0), mouse_dy_(0)
{
	position_in_middle_of_grid();
}

bool Mouse::is_alive() const
{
	return alive_;
}

bool Mouse::has_escaped() const
{
	return escaped_;
}

bool Mouse::has_reached_a_hole(Underground ug)
{
	for (int h_no(0); h_no < ug.holes_.size(); ++h_no)
	{
		Hole h = ug.get_hole_no(h_no);

		if (is_at_position(h.get_x(), h.get_y()))
		{
			return true;
		}
	}

	return false;
}

void Mouse::die()
{
	alive_ = false;
}

void Mouse::escape_into_hole()
{
	escaped_ = true;
}

void Mouse::scamper(char k)
{
	// move mouse in required direction
	// pre: k is an arrow representing the direction in which the mouse moves

	// find direction indicated by k
	switch (k)
	{
		case LEFT:
			mouse_dx_ = -1;
			mouse_dy_ = 0;
			break;
		case RIGHT:
			mouse_dx_ = +1;
			mouse_dy_ = 0;
			break;
		case UP:
			mouse_dx_ = 0;
			mouse_dy_ = -1;
			break;
		case DOWN:
			mouse_dx_ = 0;
			mouse_dy_ = +1;
			break;
	}

	// update mouse coordinates if move is possible
	if (((get_x() + mouse_dx_) >= 1) && ((get_x() + mouse_dx_) <= SIZE) && ((get_y() + mouse_dy_) >= 1) && ((get_y() + mouse_dy_) <= SIZE))
	{
		update_position(mouse_dx_, mouse_dy_);
	}
}

void Mouse::position_in_middle_of_grid()
{
	set_x(SIZE / 2);
	set_y(SIZE / 2);
}