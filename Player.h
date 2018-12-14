#pragma once
#include "Score.h"
#include <string>
using namespace std;


class Player {
	public : 
		string get_name() const;
		void set_name();
		int get_score() const;
		void update_score(int);
	
	private:
		string name_;
		Score score_;


};