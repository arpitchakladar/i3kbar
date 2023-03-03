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
	printf("{\"name\":\"%s\",\"separator_block_width\":0,\"separator\":false,\"border\":\"%s\",\"border_left\":0,\"border_right\":0,\"color\":\"%s\",\"full_text\":\" %s ", name, _accent_color, _color, icon);
	callback();
	printf(" \"},{\"name\":\"separator\",\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false,\"border\":\"%s\",\"border_left\":0,\"border_right\":0},", _accent_color, _accent_color);
}

void create_text_block(const char* name, const char* icon, const char* text, enum Color color) {
	const char* _color = get_color_hex(color);
	printf("{\"name\":\"%s\",\"full_text\":\" %s %s \",\"border\":\"%s\",\"border_left\":0,\"border_right\":0,\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false},{\"name\":\"separator\",\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false,\"border\":\"%s\",\"border_left\":0,\"border_right\":0},", name, icon, text, _accent_color, _color, _accent_color, _accent_color);
}
