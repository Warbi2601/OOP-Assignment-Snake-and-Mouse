//#include "Mouse.h"
//#include "Snake.h"
//#include "Underground.h"
//#include "UserInterface.h"
#include "Game.h"

#include <iostream>
#include <sstream>

using namespace std;

Game::Game() : nut_(Nut(8, 9)) {

}

void Game::set_up(UserInterface* pui)
{
	// set up player
	

	// set up snake
	snake_.position_at_random();
	snake_.spot_mouse(&mouse_);
	
	// set up the UserInterface
	p_ui = pui;
}

void Game::run()
{
	assert(p_ui != nullptr);

	player_.set_name(p_ui->ask_user_for_player_name());

	do
	{
		//Reset mouse, smake and nut
		mouse_.reset_mouse();
		nut_.reset_nut();
		snake_.position_at_random();

		p_ui->draw_grid_on_screen(prepare_grid());
		p_ui->show_player_info(player_.get_name(), player_.get_score());
		key_ = p_ui->get_keypress_from_user();

		while (!has_ended(key_))
		{
			if (is_arrow_key_code(key_))
			{
				mouse_.scamper(key_);
				snake_.chase_mouse();
				p_ui->draw_grid_on_screen(prepare_grid());
				p_ui->show_player_info(player_.get_name(), player_.get_score());
				apply_rules();

				if (nut_.has_been_collected()) p_ui->show_results_on_screen("NUT COLLECTED, MAKE YOUR WAY TO A HOLE");
			}

			key_ = p_ui->get_keypress_from_user();
		}

		p_ui->show_results_on_screen(prepare_end_message());

		if (mouse_.is_alive())
		{
			player_.update_score(1);
		}
		else if (snake_.has_caught_mouse())
		{
			player_.update_score(-1);
		}
	} 
	while (p_ui->ask_if_users_wants_to_play_again());
}

string Game::prepare_grid()
{
	// this function builds up a big string which holds the entire game state

	ostringstream os;

	for (int col(1); col <= SIZE; ++col)
	{
		for (int row(1); row <= SIZE; ++row)
		{
			if (snake_.is_at_position(row, col))
			{
				os << snake_.get_symbol();
			}
			else if (snake_.get_tail(row, col)) {
				os << SNAKETAIL;
			}
			else
			{
				if (mouse_.is_at_position(row, col))
				{
					os << mouse_.get_symbol();
				}
				else
				{
 					if (nut_.is_at_position(row, col))
					{
						os << (nut_.has_been_collected() ? FREECELL : nut_.get_symbol());
					}
					else
					{
						const int hole_no(find_hole_number_at_position(col, row));

						if (hole_no != -1)
							os << underground_.get_hole_no(hole_no).get_symbol();
						else
							os << FREECELL;
					}
				}
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
		if (underground_.has_reached_a_hole(mouse_))
		{
			if (nut_.has_been_collected())
			{
				mouse_.escape_into_hole();
			}
			else
			{
				//error message saying "You can't escape without the nut!" or something
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
			os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
		}
		else
		{
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
		}
	}
	return os.str();
}
