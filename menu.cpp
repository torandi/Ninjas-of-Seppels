#include "menu.h"

namespace seppels {

	MainMenu::MainMenu()
	{
		_wnd = newwin(20,14,0,0);	
		_options = new std::string[6];
		_options[0] = "inventory";
		_options[1] = "stats";
		_options[2] = "options";
		_options[3] = "load";
		_options[4] = "save";
		_options[5] = "quit";
	}

	WINDOW* MainMenu::draw_menu()
	{	
		wclear(_wnd);	
		curs_set(0); // Get rid of console cursor (we will print our own)

		
		// UTF-8 trams
		//wborder(wnd, L'│', L'│', L'─',L'─',L'╭', L'╮',L'╰',L'╯');
		box(_wnd,0,0);
		for(int i = 0; i < 6; ++i)
		{
			mvwaddstr(_wnd,(2+i),3, _options[i].c_str());	
		}

		mvwaddch(_wnd,2+Menu::_curr_selection,2, '>');
		return _wnd;
	}

	void MainMenu::select(int row)
	{
		_curr_selection = row;
	}


	BattleMenu::BattleMenu()
	{
		///TODO
	}

	WINDOW* BattleMenu::draw_Menu()
	{
		///TODO
	}

}
