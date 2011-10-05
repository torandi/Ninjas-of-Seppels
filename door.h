#ifndef DOOR_H
#define DOOR_H
namespace seppels {

	class Door {
		public:
			Door(std::string target, Gfx gfx, bool allow_entry=true, Entity required_item=NULL); 
	};
}
#endif
