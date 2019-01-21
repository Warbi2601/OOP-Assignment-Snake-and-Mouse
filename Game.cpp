//#include "Mouse.h"
//#include "Snake.h"
//#include "Underground.h"
//#include "UserInterface.h"
#include "Game.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Game::Game() : nut_(Nut(8, 9)) {

}

void Game::set_up(UserInterface* pui)
{
	// set up player

	// set up snake
	snake_.spot_mouse(&mouse_);
	
	// set up the UserInterface
	p_ui = pui;
}

void Game::run()
{
	assert(p_ui != nullptr);

	player_.set_name(p_ui->ask_user_for_player_name());

	do {
		// Reset mouse, snake and nut
		mouse_.reset_mouse();
		nut_.reset_nut();
		snake_.position_at_random();
		snake_.remove_stun(true);
		bomb_.reset();
		player_.set_used_bomb(false);

		undo = false;
		render();
		key_ = p_ui->get_keypress_from_user();

		while (!has_ended(key_))
		{
			if (is_arrow_key_code(key_))
			{
				mouse_.scamper(key_);
				
				if (snake_.is_stunned()) {
					snake_.remove_stun(false);
				}
				else {
					if (cheatActivated == false) {
						snake_.chase_mouse();
					}
				}

				undo = true;
				render();

				apply_rules();

				if (nut_.has_been_collected()) p_ui->show_results_on_screen("NUT COLLECTED, MAKE YOUR WAY TO A HOLE");
			}
			// Extension
			else if (is_cheat_key_code(toupper(key_)))
			{
				cheatActivated = !cheatActivated;
				cheatUsedInGame = true;
				render();
			}
			else if (is_undo_key_code(toupper(key_))) {
				if(undo) {
					snake_.undo_position();
					mouse_.undo_position();
					// TODO uncomment this line when Nut is changed to MoveableGridItem
					// nut_.undo_postion();

					undo = false;
					render();
				}
			}
			else if (is_file_key_code(toupper(key_))) {
				file(key_);
			}
			else if (is_bomb_key_code(toupper(key_))) {
				if (!player_.has_used_bomb() || cheatActivated) {
					bomb_.set_x(mouse_.get_x());
					bomb_.set_y(mouse_.get_y());

					bomb_.set_active(true);
					player_.set_used_bomb(true);
				}
			}

			key_ = p_ui->get_keypress_from_user();
		}

		p_ui->show_results_on_screen(prepare_end_message());

		if (mouse_.is_alive() && cheatUsedInGame == false)
		{
			player_.update_score(1);
		}
		else if (snake_.has_caught_mouse() && cheatUsedInGame == false)
		{
			player_.update_score(-1);
		}

		//reset cheats for new round
		cheatActivated = false;
		cheatUsedInGame = false;
	} 
	while (p_ui->ask_if_users_wants_to_play_again());
}

void Game::render() {
	p_ui->draw_grid_on_screen(prepare_grid());
	p_ui->show_player_info(player_.get_name(), player_.get_score());
	// Extension
	p_ui->show_cheat_info(cheatActivated);
	p_ui->show_undo_info(undo);
	p_ui->show_bomb_info(!player_.has_used_bomb() || cheatActivated);
}

string Game::prepare_grid()
{
	// this function builds up a big string which holds the entire game state
	ostringstream os;

	for (int col(1); col <= SIZE; ++col)
	{
		for (int row(1); row <= SIZE; ++row)
		{
			if (bomb_.is_active()) {
				if (bomb_.has_exploded()) {
					if (bomb_.check_explosion(row, col)) {
						os << '*';
						continue;
					}
				}
				else if (bomb_.is_at_position(row, col)) {
					os << bomb_.get_time();
					continue;
				}
			}
			
			if (snake_.is_at_position(row, col))
			{
				os << (snake_.is_stunned() ? '$' : snake_.get_symbol());
			}
			else if (snake_.get_tail(row, col)) {
				os << SNAKETAIL;
			}
			else if (mouse_.is_at_position(row, col)) {
				os << mouse_.get_symbol();
			}
			else if (nut_.is_at_position(row, col)) {
				os << (nut_.has_been_collected() ? FREECELL : nut_.get_symbol());
			}
			else {
				const int hole_no(find_hole_number_at_position(row, col));

				if (hole_no != -1)
					os << underground_.get_hole_no(hole_no).get_symbol();
				else
					os << FREECELL;
			}
		}
		os << endl;
	}

	return os.str();
}

bool Game::is_arrow_key_code(int keycode)
{
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}

bool Game::is_cheat_key_code(int keycode)
{
	return (keycode == CHEAT);
}

bool Game::is_undo_key_code(int keycode)
{
	return (keycode == UNDO);
}

bool Game::is_file_key_code(int keycode) {
	return (keycode == SAVE) || (keycode == LOAD);
}

void Game::file(char k) {
	switch (k) {
	case LOAD: {
		string line;
		ifstream fin;
		fin.open("Game.txt", ios::in);
		if (fin.fail()) cout << "\nerror loading game.";
		else {
			getline(fin, line);
			player_.set_name(line);
			getline(fin, line);
			player_.update_score(stoi(line));
			getline(fin, line);
			mouse_.set_x(stoi(line));
			getline(fin, line);
			mouse_.set_y(stoi(line));
			getline(fin, line);
			snake_.set_x(stoi(line));
			getline(fin, line);
			snake_.set_y(stoi(line));
			getline(fin, line);
			if (stoi(line) == 0) nut_.set_nut(false);
			else nut_.set_nut(true);
			snake_.clear_tail();
			render();
			cout << "\nLoad was successful";
		}
		fin.close();
		break;
	}
	case SAVE: {
		ofstream fout;
		fout.open("Game.txt", ios::out);
		if (fout.fail()) cout << "\nError saving game.";
		else {
			fout << player_.get_name() << "\n";
			fout << player_.get_score() << "\n";
			fout << mouse_.get_x() << "\n";
			fout << mouse_.get_y() << "\n";
			fout << snake_.get_x() << "\n";
			fout << snake_.get_y() << "\n";
			fout << nut_.has_been_collected() << "\n";
			render();
			cout << "\nSave Successful.";
		}
		fout.close();
		break;
	}
	}
}


bool Game::is_bomb_key_code(int keycode)
{
	return (keycode == BOMB);
}

int Game::find_hole_number_at_position(int x, int y)
{
	for (int h_no(0); h_no < underground_.getHoles().size(); ++h_no)
	{
		if (underground_.get_hole_no(h_no).is_at_position(x, y))
		{
			return h_no;
		}
	}

	return -1; // not a hole
}

void Game::apply_rules()
{
	//potentially change into switch statement
	if (snake_.has_caught_mouse())
	{
		mouse_.die();
	}
	else
	{
		if (bomb_.is_active()) {
			if (bomb_.has_exploded()) {
				if (mouse_.check_explosion(bomb_.get_x(), bomb_.get_y())) {
					mouse_.die();
				}
				if (snake_.check_explosion(bomb_.get_x(), bomb_.get_y())) {
					snake_.stun();
				}

				bomb_.reset();
			}
			else {
				bomb_.tick();
			}
		}

		if (underground_.has_reached_a_hole(mouse_))
		{
			if (nut_.has_been_collected())
			{
				mouse_.escape_into_hole();
			}
			else
			{
				p_ui->show_results_on_screen("The mouse runs into the hole without the nut and resurfaces from a different hole");
				underground_.get_random_hole_for_mouse(mouse_);
			}
		}
		else
		{
			if((nut_.is_at_position(mouse_.get_x(), mouse_.get_y())) && (!nut_.has_been_collected()))
			{
				nut_.collect_nut();
			}
		}
	}
}

bool Game::has_ended(char key)
{
	return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}

string Game::prepare_end_message()
{
	ostringstream os;
	if (mouse_.has_escaped())
	{
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";
	}
	else
	{
		if (!mouse_.is_alive())
		{
			os << "\n\nEND OF GAME: THE MOUSE DIED!";
		}
		else
		{
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
		}
	}
	return os.str();
}