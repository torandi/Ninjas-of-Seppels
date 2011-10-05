#include "screen.h"

namespace seppels {

	Screen::Screen()
	{
		init();
		cbreak();
		keypad(stdscr,true);
	}

	Screen::~Screen()
	{
		endwin();
	}

	void Screen::init() {
		initscr();
	}

}
