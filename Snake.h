#pragma once

#include "Mouse.h"
#include "MoveableGridItem.h"
#include "RandomNumberGenerator.h"

class Snake : public MoveableGridItem {
	public:
		Snake();
		~Snake();
		bool is_at_position(int x, int y);  
		bool has_caught_mouse() ;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		void position_at_random();
		char symbol_;
		int x_, y_;
		Mouse* p_mouse_;
		RandomNumberGenerator rng_;
};
