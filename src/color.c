#include "color.h"

static const char* _color_hex[] = {
	"#282828", // Background
	"#ebdbb2", // Foreground
	"#282828", // Black
	"#928374", // DarkGrey
	"#cc241d", // DarkRed
	"#fb4934", // Red
	"#98971a", // DarkGreen
	"#b8bb26", // Green
	"#d79921", // DarkYellow
	"#fabd2f", // Yellow
	"#458588", // DarkBlue
	"#83a598", // Blue
	"#b16286", // DarkMagenta
	"#d3869b", // Magenta
	"#689d6a", // DarkCyan
	"#8ec07c", // Cyan
	"#a89984", // LightGrey
	"#ebdbb2"  // White
};

const char* get_color_hex(enum Color color) {
	return _color_hex[color];
}
