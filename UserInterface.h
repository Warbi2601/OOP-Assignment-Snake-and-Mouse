#pragma once

#include <iostream>		
#include <string>		

using namespace std;

class UserInterface
{
	public:
		int get_keypress_from_user() const;
		void draw_grid_on_screen(const string& grid_data) const;
		void show_results_on_screen(string message) const;
		void hold_window();
		bool ask_if_users_wants_to_play_again() const;
		string ask_user_for_player_name() const;
		void show_player_info(string, int) const;
		void show_cheat_info(const bool cheatActivated) const;
		void show_undo_info(const bool undo) const;
		void show_bomb_info(const bool bombAvailable) const;
};