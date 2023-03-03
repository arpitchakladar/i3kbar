#include <stddef.h>

#pragma once

#ifndef DESKTOP_MODE

void initialize_battery();
void update_battery(size_t);
void show_battery();

#endif
