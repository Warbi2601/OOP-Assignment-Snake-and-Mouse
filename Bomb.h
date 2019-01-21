#pragma once
#include "MoveableGridItem.h"

class Bomb : public MoveableGridItem {
private:
	int time_;
	bool active_;
public:
	Bomb();

	void reset();
	int get_time();
	int tick();
	bool has_exploded();
	bool is_active();
	void set_active(bool active);
};

