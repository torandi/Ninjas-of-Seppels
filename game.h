#ifndef GAME_H
#define GAME_H

#include "condition.h"

#include <vector>
#include <string>

namespace seppels {
	//Forward decl. of FileParser:
	class FileParser;

	class Game {
		friend class FileParser;
		
		std::vector<condition> _victor_conditions;

	public:
		Game(std::string it, std::string egt);
		const std::string intro_text;
		const std::string endgame_text;
	};
}
#endif
