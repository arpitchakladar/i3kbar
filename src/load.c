#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "load.h"
#include "block.h"
#include "color.h"

static char _load;
static size_t _core_count = 0;

void initialize_load() {
	FILE *cpu_info_file = fopen("/proc/cpuinfo", "r");
	char buffer[10];
	size_t l = fread(buffer, sizeof(char), 10, cpu_info_file);
	// printf("%s\n", buffer);
	for (size_t i = 0; i < l; i++) {
		if (isdigit(buffer[i])) {
			_core_count = _core_count * 10 + (buffer[i] - '0');
		} else {
			break;
		}
	}
}

void update_load(size_t secs_passed) {
	if (secs_passed % 5 == 0) {
		double load;
		getloadavg(&load, 1);
		load = (load / _core_count) * 100;
		_load = load >= 100 ? 100 : (char) load;
	}
}

static void _show_load() {
	printf("%02d%%", _load);
}

void show_load() {
	create_function_block("load", "󰖡", _show_load, Green);
}
