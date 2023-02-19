#include "color.h"

#pragma once

void create_starting_block();
void create_ending_block();
void create_function_block(const char*, const char*, void (*)(), enum Color);
void create_text_block(const char*, const char*, const char*, enum Color);
