//#ifndef UserInterfaceH
//#define UserInterfaceH 


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
};

//#endif