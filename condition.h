#ifndef CONDITION_H
#define CONDITION_H

#include <string>

namespace seppels {
	enum condition_type_t {
		COND_VARIABLE,
		COND_ENTITY_FLAG,
		COND_ITEM_POSSESION
	};

	struct condition {
		condition_type_t type;
		std::string name; 
		std::string extra; //Used for entity flag
	};
}

#endif
