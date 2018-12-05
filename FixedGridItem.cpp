#include "FixedGridItem.h"

FixedGridItem::FixedGridItem(char symbol, int x, int y) : GridItem(symbol), x_(x), y_(y)
{

}

const int FixedGridItem::get_x() {
	return x_;
}

const int FixedGridItem::get_y() {
	return y_;
}

bool FixedGridItem::is_at_position(int x, int y) {
	return (x_ == x) && (y_ == y);
}