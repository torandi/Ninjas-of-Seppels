#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <map>
#include <string>
#include <exception>
#include "game.h"
#include "color.h"
#include "condition.h"

namespace seppels {
	class FileParser {
		static std::vector<color> _color_map;

		static void parse_room(std::string room_file);
		static std::map<std::string, std::string> parse_file(std::string file);

		static int get_or_create_color(color c);
		static std::vector<condition> parse_conditions(std::string cond);
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
