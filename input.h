#ifndef INPUT_H
#define INPUT_H

#include <ncurses.h>

namespace seppels {

	class Input {
		
		private:
			std::map<char,void (*callback) (char)> _callbacks;
		public:
			Input();
			~Input();

			void process();
			void register_callback(void (*callback) (char), char c);

	}

}

#endif
