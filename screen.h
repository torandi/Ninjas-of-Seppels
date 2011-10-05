#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include "color.h"

namespace seppels {

	class Screen {

		public:
			Screen();
			~Screen();			
			void init();
			void draw_char(char c, int xpos, int ypos, color p);
			

	};

}
#endif
