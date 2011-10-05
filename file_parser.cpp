#include <map>
#include <string>
#include <iostream>
#include <fstream>

#include "file_parser.h"

#include "game.h"
#include "room.h"

namespace seppels {

	inline std::string trim(std::string str) {	
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ')+1);
		return str;
	}

	std::vector<color> FileParser::_color_map;

	void FileParser::parse_room(std::string room_file) {

	}

	std::map<std::string, std::string> FileParser::parse_file(std::string file_name) {
		std::ifstream file(("data/"+file_name).c_str());
		std::map<std::string, std::string> data = std::map<std::string, std::string>();


		if(file.is_open()) {
			std::string cur_var_name="";
			std::string cur_var_content="";
			bool ignore=false;
			while(file.good()) {
				std::string line;
				std::getline(file,line);
				//Parse 
				for(unsigned int i=0;i<line.length(); ++i) {
					if(!ignore) {
						switch(line[i]) {
							case ':':
								if(cur_var_name == "") {
									cur_var_name = line.substr(0,i);
									cur_var_content = "";
								}
								break;
							case ';':
								if(i==0 || line[i-1] != '\\') {
									//Trim content:
									//Store variable:
									std::cout<<"Set "<<cur_var_name<<std::endl;
									data[cur_var_name] = trim(cur_var_content);
									cur_var_name = "";
								}
								break;
							case '*':
								if(i!=0 && line[i-1] == '/' && (i<2 || line[i-2]!='\\') ) {
									ignore = true;
								}
								break;
							default:
								cur_var_content+=line[i];
						}
					} else {
						if(i!=0 && line[i]=='/' && line[i-1] == '*') 
							ignore = false;
					}
				}	
			}
			if(cur_var_name!="") {
				std::cout<<"Error! Missing line ending of last variable"<<std::endl;
				std::cout<<cur_var_name<<":"<<cur_var_content<<std::endl;
			}
			return data;
		} else {
			throw ParseException( "Failed to open file "+file_name);
		}
	}

	int FileParser::get_or_create_color(color c) {
		for(int i=0;i<(int)_color_map.size();++i) {
			if(_color_map[i] == c) {
				return i;
			}
		}
		_color_map.push_back(c);
		return _color_map.size()-1;
	}

	std::vector<condition> FileParser::parse_conditions(std::string cond) {
		std::vector<condition> res;
		return res;
	}

	Game FileParser::parse(std::string world_file) {
		//Restore color map:
		_color_map.clear();

		std::map<std::string, std::string> game_data = parse_file(world_file+".game");
		std::map<std::string, std::string>::iterator it;
		for(it = game_data.begin(); it!=game_data.end(); ++it) {
			std::cout<<it->first<<": "<<it->second<<std::endl;
		}

		return Game(game_data["intro_text"], game_data["endgame_text"]);
	}

	const char* ParseException::what() const throw() {
		return _error.c_str();
	}


	ParseException::ParseException(std::string error) : _error(error) { }
	ParseException::~ParseException() throw() { }

}
