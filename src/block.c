#include <stdio.h>

#include "block.h"

void create_starting_block() {
	printf("[{\"full_text\":\"\",\"color\":\"#98971a\",\"separator_block_width\":7},");
}

void create_ending_block() {
	printf("{\"full_text\":\"\",\"color\":\"#98971a\"}],\n");
}

void create_block(const char* name, const char* text, const char* color) {
	printf("{\"full_text\":\"\",\"color\":\"%s\",\"separator\":false,\"separator_block_width\":0},{\"name\":\"%s\",\"full_text\":\" %s \",\"color\":\"%s\",\"border\":\"%s\",\"separator\":false,\"separator_block_width\":0},{\"full_text\":\"\",\"color\":\"%s\",\"separator_block_width\":7},", color, name, text, color, color, color);
}
