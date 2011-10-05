#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <cstdio>

namespace seppels {
	struct color {
		short r;
		short g;
		short b;

		bool operator==(color &other) const {
			return (r == other.r && g == other.g && b == other.b);
		}

		static color parse(std::string clr) {
			color ret;
			sscanf(clr.c_str(), "%2hx%2hx%2hx", &ret.r, &ret.g, &ret.b);
			return ret;
		}
	};
}
#endif
