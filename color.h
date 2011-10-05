#ifndef COLOR_H
#define COLOR_H
namespace seppels {
	struct color {
		short r;
		short g;
		short b;

		bool operator==(color &other) const {
			return (r == other.r && g == other.g && b == other.b);
		}
	};
}
#endif
