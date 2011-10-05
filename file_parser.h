#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <map>
#include <string>

namespace {
	class FileParser {

		static void parse_room(std::string room_file);
		static std::map<std::string, std::string> parse_file(std::string file);
	public:
		static Game parse(std::string world_file);
	};
}
#endif
