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
	x_ = x;
}

void MoveableGridItem::set_y(int y) {
	y_ = y;
}

bool MoveableGridItem::is_at_position(int x, int y) {
	return (x_ == x) && (y_ == y);
}

void MoveableGridItem::update_position(int dx, int dy) {
	x_ += dx;
	y_ += dy;
}