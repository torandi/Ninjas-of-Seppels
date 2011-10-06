#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <map>
#include <list>
#include <vector>
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
		static std::list<std::pair<std::string, std::string> > _used_entity_names;

		static void parse_room(std::string room_name, Game &game);
		static std::map<std::string, std::string> parse_file(std::string file);

		static int get_or_create_color(color c);
		//Loc is a string specifying location (for error output)
		static std::list<std::string> * parse_list(std::string strlist, std::string loc);
		static std::list<condition> parse_conditions(std::string cond, std::string loc);
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
