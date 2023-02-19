#include <stdio.h>

#include "block.h"
#include "color.h"

void create_starting_block() {
	printf("[{\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false},", get_color_hex(DarkGrey));
}

void create_ending_block() {
	printf("{\"full_text\":\"\",\"color\":\"%s\"}],\n", get_color_hex(DarkGrey));
}

void create_function_block(const char* name, const char *icon, void (*callback)(), enum Color color) {
	const char* _color = get_color_hex(color);
	printf("{\"full_text\":\"\",\"color\":\"%s\",\"separator\":false,\"separator_block_width\":0},{\"name\":\"%s\",\"full_text\":\" %s ", _color, name, icon);
	callback();
	printf(" \",\"color\":\"%s\",\"border\":\"%s\",\"separator\":false,\"separator_block_width\":0},{\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false},", _color, _color, _color);
}

void create_text_block(const char* name, const char *icon, const char* text, enum Color color) {
	const char* _color = get_color_hex(color);
	printf("{\"full_text\":\"\",\"color\":\"%s\",\"separator\":false,\"separator_block_width\":0},{\"name\":\"%s\",\"full_text\":\" %s %s \",\"color\":\"%s\",\"border\":\"%s\",\"separator\":false,\"separator_block_width\":0},{\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false},", _color, name, icon, text, _color, _color, _color);
}
