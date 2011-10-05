#ifndef ROOM_H
#define ROOM_H

#include "coordinate.h"
#include "door.h"
#include "entity.h"
#include "file_parser.h"

namespace seppels {
	class Room {
		friend class FileParser;
		
		std::map<int,Door> doors;
		std::map<coordinate, Entity> entities;


		public:
			Room(std::string name);
	};
}

#endif
