#ifndef GFX_H
#define GFX_H
namespace seppels {
	struct gfx {
		short color;
		char c;

		gfx(short clr, char chr) : color(clr), c(chr) {};
		gfx() : color(0), c(' ') {};
	};
}
#endif
