#include "MoveableGridItem.h"

MoveableGridItem::MoveableGridItem(char symbol, int x, int y) : GridItem(symbol), x_(x), y_(y)
{
	
}

int MoveableGridItem::get_x() {
	return x_;
}

int MoveableGridItem::get_y() {
	return y_;
}

void MoveableGridItem::set_x(int x) {
	lastPos.x_ = x_;
	x_ = x;
}

void MoveableGridItem::set_y(int y) {
	lastPos.y_ = y_;
	y_ = y;
}

bool MoveableGridItem::is_at_position(int x, int y) {
	return (x_ == x) && (y_ == y);
}

void MoveableGridItem::update_position(int dx, int dy) {
	lastPos.x_ = x_;
	lastPos.y_ = y_;

	x_ += dx;
	y_ += dy;
}

void MoveableGridItem::undo_position()
{
	// CHECK FOR NULL VALUES
	x_ = lastPos.x_;
	y_ = lastPos.y_;
}

