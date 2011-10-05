#ifndef GAME_H
#define GAME_H

#include "condition.h"
#include "entity.h"
#include "gfx.h"

#include <vector>
#include <string>
#include <map>

namespace seppels {
	//Forward decl. of FileParser:
	//class FileParser;

	class Game {
		friend class FileParser;
		
		std::vector<condition> _victory_conditions;
		std::map<std::string, Entity> _named_entities;

		gfx _wall_gfx;

	public:
		const std::string intro_text;
		const std::string endgame_text;

		Game(std::string it, std::string egt);
	};
}
#endif
