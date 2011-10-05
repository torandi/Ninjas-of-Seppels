#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "coordinate.h"
#include "door.h"
#include "entity.h"
#include "file_parser.h"

namespace seppels {
	class Room {
		friend class FileParser;
		
		std::map<int,Door> _doors;
		std::map<coordinate, Entity> _entities;
		std::vector<std::pair<coordinate, gfx> > _graphics;
		char **_map; 

		int _width, _height;

		public:
			Room(std::string name);
	};
}

#endif
