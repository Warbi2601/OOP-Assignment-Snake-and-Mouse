#pragma once

#include "GridItem.h"

class FixedGridItem : public GridItem
{
public:
	FixedGridItem(char symbol, int x, int y);

	const int get_x();
	const int get_y();
	bool is_at_position(int x, int y);
private:
	int x_;
	int y_;
};

