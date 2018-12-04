#include <iostream>		// for output and input
#include <string>		// for string
#include <sstream>		// for streamstring

using namespace std;

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"
#include "Game.h"

int main()
{
	// using OO approach
	UserInterface ui;

	Game game;

	game.set_up(&ui);
	game.run();

	ui.hold_window();
	return 0;
}