#pragma once

#include <cassert>
#include <vector>

#include "constants.h"
#include "RandomNumberGenerator.h"
#include "FixedGridItem.h"
#include "Mouse.h"

using namespace std;

class Hole : public FixedGridItem
{
	public:
		// constructors
		Hole(int x, int y);

	private:
		static const int MAXHOLES; // number of holes in underground
};

class Underground
{
	public:
		Underground();
		Hole get_hole_no(int no) const;
		// void set_hole_no_at_position(int no, int x, int y);
		bool is_valid_hole_number(int n) const;
		bool has_reached_a_hole(Mouse& mouse) const;
		vector<Hole> getHoles() const;
		void get_random_hole_for_mouse(Mouse& mouse) const;

	private:
		const vector<Hole> holes_;
};
