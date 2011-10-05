#include "screen.h"
#include <time.h>

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
		_mainwnd = initscr();
	}

	void Screen::scrolling_text(std::list<string> lines) {
		curs_set(0);
		WINDOW* wnd = newwin(30,80,0,0);
		box(wnd,0,0);
		wrefresh(wnd);
		int row = 28;

		for(it = lines.begin(); it != lines.end(); ++lines)
		{	
			for(int i = 0; i<2; ++i)
			{
				mvwprintw(wnd,28,1,"_");
				wrefresh(wnd);
				sleep(1);
				mvwprintw(wnd,28,1," ");
				wrefresh(wnd);
				sleep(1);
			}
			for(cit = (*it).begin(), cit != (*it).end(), ++(*it))
			{
				
			}

		}
	}

}
