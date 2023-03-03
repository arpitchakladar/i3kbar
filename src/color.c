#include "color.h"

static const char* _color_hex[] = {
	"#282828", // Black
	"#cc241d", // DarkRed
	"#98971a", // DarkGreen
	"#d79921", // DarkYellow
	"#458588", // DarkBlue
	"#b16286", // DarkMagenta
	"#689d6a", // DarkCyan
	"#a89984", // LightGrey
	"#928374", // DarkGrey
	"#fb4934", // Red
	"#b8bb26", // Green
	"#fabd2f", // Yellow
	"#729587", // Blue
	"#d3869b", // Magenta
	"#8ec07c", // Cyan
	"#ebdbb2", // White
	"#282828", // Background
	"#928374"  // Accent
};

const char* get_color_hex(enum Color color) {
	return _color_hex[color];
}
