#ifndef ROOM_H
#define ROOM_H

namespace seppels {
	class Room {
		friend class FileParser;
		
		std::map<int,Door> doors;
		std::map<Coordinate, Entity> entities;


		public:
			Room(std::string name);
	};
}

#endif
