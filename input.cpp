#include "input.h"

namespace seppels {

	typedef char (*callback) (void);

	Input::Input()
	{
		_callbacks = new std::map<char,callback>();
	}

	Input::~Input()
	{
		delete &_callbacks;
	}

	void Input::register_callback(char (*func) (void), char c)
	{
		(*_callbacks)[c] = func;
	}

	void Input::process(char c)
	{
		(*_callbacks)[c]();
	}
}
