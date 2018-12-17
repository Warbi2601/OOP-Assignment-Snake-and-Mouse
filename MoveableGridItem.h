#pragma once
#include "GridItem.h"

class MoveableGridItem : public GridItem
{
public:
	MoveableGridItem(char symbol, int x, int y);
	
	int get_x();
	int get_y();
	void set_x(int);
	void set_y(int);

	bool is_at_position(int x, int y);
	void update_position(int dx, int dy);
private:
	int x_;
	int y_;
};

