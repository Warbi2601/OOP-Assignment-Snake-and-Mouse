#ifndef UndergroundH
#define UndergroundH 


#include <cassert>
#include <vector>

#include "constants.h"
#include "RandomNumberGenerator.h"

using namespace std;

class Hole
{
	public:
		// constructors
		Hole();
		Hole(int x, int y);

		// assessors
		int get_x();
		int get_y();
		char get_symbol() const;
		bool is_at_position(int x, int y);

	private:
		static const int MAXHOLES; // number of holes in underground

		// data members
		char symbol_;
		int x_, y_;
};

class Underground
{
	public:
		Underground();
		Hole get_hole_no(int no) const;
		void set_hole_no_at_position(int no, int x, int y);
		bool is_valid_hole_number(int n) const;
		vector<Hole> holes_;
};

#endif