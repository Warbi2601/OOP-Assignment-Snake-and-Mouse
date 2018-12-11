#ifndef MouseH 
#define MouseH 

#include "constants.h"
#include "MoveableGridItem.h"
#include "Underground.h"

class Mouse : public MoveableGridItem
{
	public:
		// constructor
		Mouse();

		// assessors
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(Underground ug);

		// mutators
		void die();
		void escape_into_hole();
		void scamper(char k);

	private:
		// data members
		bool alive_;
		bool escaped_;
		int mouse_dx_;
		int mouse_dy_;

		// supporting functions 
		void position_in_middle_of_grid();
};

#endif