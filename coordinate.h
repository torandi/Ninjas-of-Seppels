#ifndef COORDINATE_H
#define COORDINATE_H
namespace seppels {
	struct coordinate {
		int x;
		int y;

		bool operator<(const coordinate &other) const {
			if(x < other.x) {
				return true;
			} else if(x > other.x) {
				return false;
			} else if(y < other.y) {
				return true;
			} else {
				return false;
			}
		}

		bool operator=(const coordinate &other) const {
			return (x==other.x && y==other.y);
		}
	};
}
#endif
