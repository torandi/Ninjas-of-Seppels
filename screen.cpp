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
		_mainwnd = initscr();
		_mapwnd = newwin(0,0,0,0);
		box(_mapwnd,0,0);
		_battlewnd = newwin(0,0,0,0);
		box(_battlewnd,0,0);
	}

	void Screen::scrolling_text(std::list<std::string>* lines) const {
		curs_set(0);
		WINDOW* wnd = newwin(30,80,0,0);
		WINDOW* internal = newwin(28,78,1,1);
		box(wnd,0,0);
		wrefresh(wnd);
		int col = 1;
		std::list<std::string>::iterator it;

		for(it = lines->begin(); it != lines->end(); it++)
		{	
			mvwprintw(internal,1,1,"_");
			wrefresh(internal);
			sleep(1);
			mvwprintw(wnd,1,1," ");
			wrefresh(internal);
			sleep(1);

			for(unsigned int i = 0; i < it->length(); ++i)
			{
				mvwaddch(internal,1,col,(*it)[i]);
				wrefresh(internal);
				col++;
				usleep(100*1000);
			}
			col = 1;
			winsertln(internal);
		}
		for(int i = 0; i < 2; ++i)
		{
			mvwprintw(internal,1,1,"_");
			wrefresh(internal);
			sleep(1);
			mvwprintw(wnd,1,1," ");
			wrefresh(internal);
			sleep(1);
		}

		wborder(wnd, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(wnd);
		delwin(internal);
		delwin(wnd);
	}

	void Screen::draw_room(std::vector<std::pair<coordinate,gfx> > graphics) const {
		
		std::vector<std::pair<coordinate,gfx> >::iterator it;

		for(it = graphics.begin(); it != graphics.end(); it++)
		{
			mvwaddch(_mapwnd,(*it).first.x,(*it).first.y, (*it).second.c);
		}

	}

}
