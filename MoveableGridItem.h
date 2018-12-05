#pragma once
#include "GridItem.h"

class MoveableGridItem : public GridItem
{
public:
	MoveableGridItem(char symbol, int x, int y);
	// ~MoveableGridItem();
	
	int get_x();
	int get_y();
	bool is_at_position(int x, int y);
	void update_position(int dx, int dy);
private:
	int x_;
	int y_;
};

