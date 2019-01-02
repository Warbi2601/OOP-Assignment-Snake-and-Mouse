#include <conio.h>	// for _getch()

#include "UserInterface.h" 

int UserInterface::get_keypress_from_user() const
{	//DO NOT CHANGE THIS FUNCTION
	// read in the selected arrow key or command letter
	int key_pressed(_getch());

	// ignore symbol following cursor key
	while (key_pressed == 224)
		key_pressed = _getch();

	// return the key in uppercase
	return(toupper(key_pressed));
}

void UserInterface::draw_grid_on_screen(const string& grid_data) const
{
	// clear screen
	system("cls");

	cout << grid_data << "\n";
}

void UserInterface::show_results_on_screen(string message) const
{
	cout << message;
}

void UserInterface::hold_window()
{
	cout << "\n\n";
	system("pause");
}

bool UserInterface::ask_if_users_wants_to_play_again() const
{
	cout << "\nWould you like to play again? (y/n)\n";
	char result;
	cin >> result;
	if (tolower(result) == 'y') return true;
	else return false;
}

string UserInterface::ask_user_for_player_name() const
{
	cout << "Enter your player name!\n";
	string name;
	cin >> name;
	return name;
}

void UserInterface::show_player_info(string name, int score) const
{
	cout << "Player: " << name << "\n";
	cout << "Score: " << score << "\n";
}

void UserInterface::show_cheat_info(const bool cheatActivated) const
{
	if(cheatActivated == true) cout << "Cheat Currently Active!" << "\n";
}