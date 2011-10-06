#ifndef DOOR_H
#define DOOR_H

#include <string>
#include "gfx.h"
#include "coordinate.h"

class Room; //Forward declaration of Room

namespace seppels {
	class Door {
		coordinate _pos;
		gfx _graphic;
		Room * _target;
		public:
			void render();
	};
}
#endif
