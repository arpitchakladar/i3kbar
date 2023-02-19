#include <stdio.h>

#include "block.h"

void create_starting_block() {
	printf("[{\"full_text\":\"\",\"color\":\"#a89984\",\"separator_block_width\":0,\"separator\":false},");
}

void create_ending_block() {
	printf("{\"full_text\":\"\",\"color\":\"#a89984\"}],\n");
}

void create_block(const char* name, const char *icon, const char* text, const char* color) {
	printf("{\"full_text\":\"\",\"color\":\"%s\",\"separator\":false,\"separator_block_width\":0},{\"name\":\"%s\",\"full_text\":\" %s %s \",\"color\":\"%s\",\"border\":\"%s\",\"separator\":false,\"separator_block_width\":0},{\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":0,\"separator\":false},", color, name, icon, text, color, color, color);
}
