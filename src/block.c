#include <stdio.h>

#include "block.h"
#include "color.h"

void initialize_bar() {
	printf("{\"version\":1}\n[\n");
}

void start_block() {
	printf("[{\"name\":\"start\",\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false}", get_color_hex(DarkGrey));
}

void end_block() {
	printf(",{\"name\":\"end\",\"full_text\":\"\",\"color\":\"%s\"}],\n", get_color_hex(DarkGrey));
}

void create_function_block(const char* name, const char* icon, void (*callback)(), enum Color color) {
	const char* _color = get_color_hex(color);
	printf(",{\"name\":\"%s\",\"separator_block_width\":7,\"color\":\"%s\",\"full_text\":\" %s ", name, _color, icon);
	callback();
	printf(" \"}");
}

void create_text_block(const char* name, const char* icon, const char* text, enum Color color) {
	const char* _color = get_color_hex(color);
	printf(",{\"name\":\"%s\",\"full_text\":\" %s %s \",\"color\":\"%s\",\"separator_block_width\":7}", name, icon, text, _color);
}
