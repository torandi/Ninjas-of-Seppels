#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <iostream>
#include <list>
#include <vector>
#include "gfx.h"
#include "coordinate.h"

namespace seppels {

	class Screen {

		private:
			WINDOW* _mainwnd;
			WINDOW* _mapwnd;
			WINDOW* _battlewnd;

		public:
			Screen();
			~Screen();			
			void init();

			void scrolling_text(std::list<std::string>* lines) const;
			void draw_room(std::vector<std::pair<coordinate, gfx> > graphics) const;
			
	};

}
#endif
