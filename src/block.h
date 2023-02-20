#include "color.h"

#pragma once

void initialize_bar();
void start_block();
void end_block();
void create_function_block(const char*, const char*, void (*)(), enum Color);
void create_text_block(const char*, const char*, const char*, enum Color);
