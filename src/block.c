#include <stdio.h>

#include "block.h"
#include "color.h"

static const char* _accent_color;

void initialize_bar() {
	printf("{\"version\":1}\n[\n");
	_accent_color = get_color_hex(Accent);
}

void start_block() {
	printf("[{\"name\":\"separator\",\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false},", _accent_color);
}

void end_block() {
	printf("{\"name\":\"end\",\"full_text\":\"\",\"color\":\"%s\"}],\n", _accent_color);
}

void create_function_block(const char* name, const char* icon, void (*callback)(), enum Color color) {
	const char* _color = get_color_hex(color);
	printf("{\"name\":\"%s\",\"separator_block_width\":7,\"color\":\"%s\",\"full_text\":\" %s ", name, _color, icon);
	callback();
	printf(" \"},");
}

void create_text_block(const char* name, const char* icon, const char* text, enum Color color) {
	const char* _color = get_color_hex(color);
	printf("{\"name\":\"%s\",\"full_text\":\" %s %s \",\"color\":\"%s\",\"separator_block_width\":7},", name, icon, text, _color);
}
