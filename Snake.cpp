#include "Constants.h"
#include "Snake.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

Snake::Snake() : MoveableGridItem(SNAKEHEAD, 0, 0)
{
	// make the pointer safe before the snake spots the mouse
	// p_mouse_ = nullptr;
}

bool Snake::has_caught_mouse()
{
	return is_at_position(p_mouse_->get_x(), p_mouse_->get_y());
}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: The mouse needs to exist 
	assert(p_mouse != nullptr);

	p_mouse_ = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	move_tail();

	//go in that direction
	update_position(snake_dx, snake_dy);
}

void Snake::set_direction(int& dx, int& dy)
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse_ != nullptr);

	// assume snake only move when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (get_x() < p_mouse_->get_x())          // if snake on left of mouse
		dx = 1;                          // snake should move right
	else if (get_x() > p_mouse_->get_x())     // if snake on left of mouse
		dx = -1;						 // snake should move left

	if (get_y() < p_mouse_->get_y())          // if snake is above mouse
		dy = 1;                          // snake should move down
	else if (get_y() > p_mouse_->get_y())     // if snake is below mouse
		dy = -1;						 // snake should move up
}

void Snake::move_tail() {
	int x(0), y(0), size = tail_.size();

	if (!x && !y) {
		x = get_x();
		y = get_y();
	}

	if (size > 0) {
		for (auto &item : tail_) {
			int temp_x = item.get_x(),
				temp_y = item.get_y();

			item.set_x(x);
			item.set_y(y);

			x = temp_x;
			y = temp_y;
		}
	}

	if(size < 3) {
		tail_.push_back(MoveableGridItem(SNAKETAIL, x, y));
	}
}

bool Snake::get_tail(int x, int y) {
	for (auto &item : tail_) {
		if (item.is_at_position(x, y)) {
			return true;
		}
	}
	return false;
}

void Snake::clear_tail() {
	tail_.clear();
}

void Snake::undo_position() {
	MoveableGridItem::undo_position();

	for (auto &item : tail_) {
		item.undo_position();
	}
}

bool Snake::check_explosion(int x, int y) {
	bool hit = MoveableGridItem::check_explosion(x, y);

	for (auto &item : tail_) {
		hit = (hit || item.check_explosion(x, y));
	}
	return hit;
}

void Snake::stun() {
	stunned_ = 3;
}

void Snake::remove_stun(bool reset) {
	if (reset) {
		stunned_ = 0;
	}
	else {
		stunned_--;
	}
}

bool Snake::is_stunned() {
	return stunned_ > 0;
}

const RandomNumberGenerator Snake::rng_;

void Snake::position_at_random()
{
	assert(p_mouse_ != nullptr);
	clear_tail();

	// WARNING: this may place on top of other things
	bool valid = false;
	int x(0), y(0);

	while (!valid) {
		x = rng_.get_random_value(SIZE);
		y = rng_.get_random_value(SIZE);

		int dx = (x - p_mouse_->get_x());
		int dy = (y - p_mouse_->get_y());

		double dist = sqrt(dx * dx + dy * dy);
		valid = dist > 4.20;
	}

	set_x(x);
	set_y(y);
}