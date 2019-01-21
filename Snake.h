#pragma once

#include "Mouse.h"
#include "MoveableGridItem.h"
#include "RandomNumberGenerator.h"
#include <vector>

class Snake : public MoveableGridItem {
	public:
		Snake();
		bool has_caught_mouse();
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		void position_at_random();
		void move_tail();
		void clear_tail();
		int get_tail_size();
		MoveableGridItem *get_tail(int x, int y);
		void undo_position();
		
	private:
		Mouse* p_mouse_;
		static const RandomNumberGenerator rng_;
		vector<MoveableGridItem> tail_;
};
