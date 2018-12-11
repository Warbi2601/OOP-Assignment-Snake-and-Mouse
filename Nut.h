#pragma once

class Nut {
	public:
		Nut(int, int);
		int get_x();
		int get_y();
		char get_symbol();
		bool has_been_collected();
		bool is_at_position(int, int);
		//dissapear();
	private:
		int x;
		int y;
		char symbol;
		bool collected;
};