#pragma once

#include "FixedGridItem.h"
#include "constants.h"

class Nut : public FixedGridItem {
	public:
		Nut(int, int);
		bool has_been_collected();
		void Nut::collect_nut();
		//dissapear();
	private:
		bool collected;
};