#pragma once

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"
#include "Nut.h"
#include "Player.h"
#include "Bomb.h"

#define BOMB	  (66)	// 'B'
// defining cheat keys
#define CHEAT	  (67)	// upper case 'C'
#define UNDO	  (85)	// 'U'

class Game {
public:
	Game();

	int key_;
	void set_up(UserInterface* pui);
	void run();
	string prepare_grid();
	void render();

	bool is_arrow_key_code(int keycode);
	bool is_cheat_key_code(int keycode);
	bool is_undo_key_code(int keycode);
	bool is_bomb_key_code(int keycode);
	
	void apply_rules();
	int find_hole_number_at_position(int x, int y);
	bool has_ended(char key);
	string prepare_end_message();

private:
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;
	Nut nut_;
	Player player_;
	bool cheatActivated;
	bool cheatUsedInGame;
	bool undo;
	// Changed to pointer because it kept throwing the error:
	// "attempting to reference a deleted function"
	Bomb bomb_;
};