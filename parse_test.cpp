#include <iostream>
#include <exception>
#include "file_parser.h"

using namespace seppels;

int main() {
	try {
		FileParser::parse("ninjas_of_seppels");
	} catch (std::exception &e) {
		std::cerr<<"An error occured while parsing the file: "<<e.what()<<std::endl;
	}
}
