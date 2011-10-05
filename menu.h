#ifndef MENU_H
#define MENU_H
#include <string>
#include <ncurses.h>

namespace seppels {

 	class Menu
 	{
		protected:
			int _curr_selection;

		public:
			Menu() : _curr_selection(0){};
			virtual WINDOW* draw_menu() = 0;
	};

  
	class MainMenu : public Menu
	{
		std::string *_options;
		WINDOW* _wnd;

		public:
			MainMenu();
			virtual WINDOW* draw_menu();
		 	void select(int row);
	};

	class InventoryMenu : Menu
	{

	};

	class BattleMenu : Menu
	{
		public:
			BattleMenu();
			virtual WINDOW* draw_menu();
	};
}
#endif
