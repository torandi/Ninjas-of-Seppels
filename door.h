#ifndef DOOR_H
#define DOOR_H

#include <string>
#include "gfx.h"

namespace seppels {

	class Door {
		public:
			Door(std::string target, gfx look, bool allow_entry=true); //Add open conditions 
	};
}
#endif
