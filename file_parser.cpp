#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "file_parser.h"

namespace seppels {

	void FileParser::parse_room(std::string room_file) {

	}

	std::map<std::string, std::string> FileParser::parse_file(std::string file_name) {
		std::ifstream file;
		std::map<std::string, std::string> data;

		file.open(file_name);

		if(file.is_open()) {
			std::string cur_var_name=NULL;
			std::string cur_var_content="";
			bool ignore=false;
			while(file.good()) {
				std::string line;
				std::getline(file,line);
				//Parse 
				for(int i=0;i<line.length(); ++i) {
					if(!ignore) {
						switch(line[i]) {
							case ':':
								if(cur_var_name == NULL) {
									cur_var_name = line.substr(0,i-1);
									cur_var_content = "";
								}
								break;
							case ';':
								if(i==0 || line[i-1] != '\\') {
									//Trim content:
									cur_var_content.erase(0, cur_var_content.find_first_not_of(' '));
									cur_var_content.erase(cur_var_content.find_last_not_of(' ')+1);
									//Store variable:
									data[cur_var_name] = cur_var_content;
									cur_var_name = NULL;
								}
								break;
							case '*':
								if(i!=0 && line[i-1] == '/' && (i<2 || line[i-2]!='\\') ) {
									ignore = true;
								}
								break;
						}
					} else {
						if(i!=0 && line[i]=='*' && line[i-1] == '/') 
							ignore = false;
					}
				}	
			}
		} else {
			std::cout << "Failed to open file "<<file_name<<std::endl;
		}
	}

	Game FileParser::parse(std::string world_file) {
		
	}

}
