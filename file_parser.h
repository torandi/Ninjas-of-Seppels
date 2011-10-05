#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <map>
#include <string>
#include <utility>
#include <exception>
#include "game.h"
#include "color.h"
#include "condition.h"
#include "gfx.h"

namespace seppels {
	class FileParser {
		static std::vector<color> _color_map;
		/* A list of all used entity names and where they where used */
		static std::vector<std::pair<std::string, std::string> > _used_entity_names;

		static void parse_room(std::string room_file, Game &game);
		static std::map<std::string, std::string> parse_file(std::string file);

		static int get_or_create_color(color c);
		static std::vector<condition> parse_conditions(std::string cond, std::string loc);
		static gfx parse_gfx(const std::string &str);
	public:
		static Game parse(std::string game);
	};

	class ParseException : public std::exception {
		std::string _error;
		public:
			virtual const char* what() const throw(); 
			ParseException(std::string error);
			~ParseException() throw();
	};
}
#endif
