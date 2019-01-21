#pragma once
#include "Score.h"
#include <string>
using namespace std;


class Player {
	public : 
		string get_name() const;
		void set_name(string);
		int get_score() const;
		void update_score(int);
		void set_used_bomb(bool);
		bool has_used_bomb();

	private:
		string name_;
		Score score_;
		bool used_bomb_;
};