#ifndef UndergroundH
#define UndergroundH 


#include <cassert>
#include <vector>

#include "constants.h"
#include "RandomNumberGenerator.h"
#include "FixedGridItem.h"

using namespace std;

class Hole : public FixedGridItem
{
	public:
		// constructors
		Hole();
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
		vector<Hole> getHoles() const;
	private:
		const vector<Hole> holes_;
};

#endif