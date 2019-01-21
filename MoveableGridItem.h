#pragma once
#include "GridItem.h"

struct location {
	int x_;
	int y_;
};

class MoveableGridItem : public GridItem
{
private:
	int x_;
	int y_;
	location lastPos;

public:
	MoveableGridItem(char symbol, int x, int y);
	
	int get_x();
	int get_y();
	void set_x(int);
	void set_y(int);
	// location* getLastPos();

	bool is_at_position(int x, int y);
	void update_position(int dx, int dy);
	void undo_position();
	bool check_explosion(int x, int y);

};

