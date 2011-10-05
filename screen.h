#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <iostream>

namespace seppels {

	class Screen {

		private:
			WINDOW* _mainwnd;

		public:
			Screen();
			~Screen();			
			void init();

			void scrolling_text(std::string str[]);
	};

}
#endif
