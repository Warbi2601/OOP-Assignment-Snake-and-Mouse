#pragma once

#include "MoveableGridItem.h"
#include "constants.h"

class Nut : public MoveableGridItem {
	public:
		Nut(int, int);
		bool has_been_collected();
		void collect_nut();
		void reset_nut();
		void set_nut(bool);
		//dissapear();
	private:
		bool collected;
};