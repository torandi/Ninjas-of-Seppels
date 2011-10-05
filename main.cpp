#include "screen.h"
#include <list>
#include <iostream>

using namespace seppels;
int main()
{
	Screen* screen = new Screen();
	
	std::list<std::string>* text = new std::list<std::string>();
	
	text->push_front("Hello World!");
	text->push_back("Oh yeah");
	screen->scrolling_text(text);
	while(true){}
}

