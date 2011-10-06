#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <fstream>

#include "file_parser.h"

#include "game.h"
#include "room.h"
#include "condition.h"

namespace seppels {

	inline std::string trim(std::string str) {	
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ')+1);
		return str;
	}

	std::vector<color> FileParser::_color_map;
	std::list<std::pair<std::string, std::string> > FileParser::_used_entity_names;

	void FileParser::parse_room(std::string room_name, Game &game) {
		std::map<std::string, std::string> data = parse_file(room_name+".room");

		std::string map = data["map"];

		for(int i=0;i<map.length();++i) {
			
		}

		std::list<std::string> * str_doors = parse_list(data["doors"],room_name+".room:doors");
		std::cout<<"DOORS:::::"<<std::endl;
		for(std::list<std::string>::iterator it = str_doors->begin(); it!=str_doors->end(); ++it) {
			std::cout<<*it<<std::endl;
		}
		delete str_doors;

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
									data[cur_var_name] = trim(cur_var_content);
									cur_var_name = "";
								}
								break;
							case '/':
								if(i+1<line.length() && line[i+1] == '*' && (i==0 || line[i-1]!='\\') ) {
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

	gfx FileParser::parse_gfx(const std::string &str) {
		std::string content = str.substr(str.find_first_of('{')+1, str.find_last_of('}')-1);
		std::string clr_str = trim(content.substr(0,str.find_first_of(',')-1));
		std::string representation = trim(content.substr(str.find_first_of(',')+1));
		color clr = color::parse(clr_str);
		return gfx(get_or_create_color(clr), representation[0]);
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

	/*
	 * Parses a list on format {foo,bar,baz} to a linked list. Returns a pointer that must be deleted
	 */
	std::list<std::string> * FileParser::parse_list(std::string str, std::string loc) {
		if(str.find_first_of('{') == std::string::npos || str.find_last_of('}') == std::string::npos) {
			std::cerr<<"Parser warning: In "<<loc<<" "<<str<<" is not a valid list. List must be on the format {a,b,...,n}"<<std::endl;
		}
		std::string content = str.substr(str.find_first_of('{')+1, str.find_last_of('}')-1)+","; //Append , to finish the last part
		std::list<std::string> * list = new std::list<std::string>();
		int depth = 0;
		std::string part = "";
		for(unsigned int i=0;i<content.length(); ++i) {
			switch(content[i]) {
				case ',':
					if(depth == 0) {
						list->push_back(trim(part));
						part = "";
					} else {
						part.push_back(content[i]);
					}
					break;
				case '{':
					++depth;
					part.push_back(content[i]);
					break;
				case '}':
					--depth;
					part.push_back(content[i]);
					break;
				default:
					part.push_back(content[i]);
					break;
			}
		}
		if(depth != 0)
			std::cerr<<"Parser warning: In "<<loc<<" "<<str<<" ended on depth "<<depth<<std::endl;
		return list;
	}

	std::list<condition> FileParser::parse_conditions(std::string str, std::string loc) {
		std::list<condition> res;
		std::list<std::string> * list = parse_list(str,loc);
		std::list<std::string>::iterator it;
		for(it = list->begin(); it!=list->end();++it) {
			condition cnd;
			switch((*it)[0]) {
				case '$':
					//Global flag
					cnd.type = COND_FLAG;
					cnd.name = it->substr(1);
					break;
				case '@':
					cnd.type = COND_ENTITY_FLAG;
					cnd.name = it->substr(1,it->find_first_of('.')-1);
					cnd.extra = it->substr(it->find_first_of('.')+1);
					_used_entity_names.push_back(std::pair<std::string, std::string>(cnd.name, loc));
					break;
				case '#':
					cnd.type = COND_ITEM_POSSESION;
					cnd.name = it->substr(1);
					break;
				default:
					delete list;
					throw ParseException("Unknown condition in ");//+loc+": "+part);
			}
			res.push_back(cnd);
		}
		delete list;
		return res;
	}

	Game FileParser::parse(std::string game_file) {
		//Restore color map:
		_color_map.clear();
		game_file+=".game";
		std::map<std::string, std::string> game_data = parse_file(game_file);

		Game g = Game(game_data["intro_text"], game_data["endgame_text"]);
		
		g._wall_gfx = parse_gfx(game_data["wall_gfx"]);
		g._victory_conditions = parse_conditions(game_data["victory_conditions"], game_file+":victory_conditions");

		//Parse all rooms (ursivly from first room)
		parse_room(game_data["start_room"], g);

		//Verify that all used entity names have been defined:
		bool has_error=false;
		for(std::list<std::pair<std::string, std::string> >::iterator it = _used_entity_names.begin();
			it != _used_entity_names.end(); ++it) {

			if(g._named_entities.count(it->first)==0) {
				has_error=true;
				std::cerr<<"Used but undeclared entity @"<<it->first<<" in "<<it->second<<std::endl;
			}
		}
		if(has_error) {
			throw ParseException("Undeclared entities");
		}
		return g;
	}

	const char* ParseException::what() const throw() {
		return _error.c_str();
	}


	ParseException::ParseException(std::string error) : _error(error) { }
	ParseException::~ParseException() throw() { }

}
