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
		// TAIL
		void move_tail();
		void clear_tail();
		bool get_tail(int x, int y);
		void undo_position();
		bool check_explosion(int x, int y);
		void stun();
		void remove_stun(bool reset);
		bool is_stunned();
		
	private:
		Mouse* p_mouse_;
		static const RandomNumberGenerator rng_;
		vector<MoveableGridItem> tail_;
		int stunned_ = 0;
};
