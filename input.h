#ifndef INPUT_H
#define INPUT_H

#include <ncurses.h>
#include <map>

namespace seppels {

	typedef char (*callback)(void);

	class Input {
		
		private:
			std::map<char,callback>* _callbacks;
		public:
			Input();
			~Input();

			void process(char c);
			void register_callback(callback, char c);

	};

}

#endif
