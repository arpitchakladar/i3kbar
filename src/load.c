#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <inttypes.h>

#include "load.h"
#include "block.h"
#include "color.h"

static uint8_t _load;
static size_t _core_count = 0;

void initialize_load() {
	FILE *cpu_info_file = fopen("/proc/cpuinfo", "r");
	size_t i = 0;
	size_t j = 0;
	bool compare = false;
	char current_char;
	char field_name[] = "cpu cores";
	for (;;) {
		current_char = fgetc(cpu_info_file);
		if (current_char == EOF) {
			break;
		} else {
			switch (current_char) {
				case '\n':
					if (j < 9) {
						j = 0;
						compare = true;
					} else {
						goto end;
					}
					break;

				case '\t':
					if (j < 9) {
						j = 0;
					} else {
						fseek(cpu_info_file, i + 3, SEEK_SET);
						i += 2;
					}
					compare = false;
					break;

				default:
					if (compare) {
						if (field_name[j++] != current_char) {
							compare = true;
							j = 0;
						}
					} else if (j >= 9) {
						_core_count = _core_count * 10 + (current_char - '0');
					}
			}
		}
		i++;
	}
end:
	fclose(cpu_info_file);
}

void update_load(size_t secs_passed) {
	if (secs_passed % 19 == 0) {
		double load;
		getloadavg(&load, 1);
		load = (load / _core_count) * 100;
		_load = load >= 100 ? 100 : (uint8_t) load;
	}
}

static void _show_load() {
	printf("%02d%%", _load);
}

void show_load() {
	create_function_block("load", "󰖡", _show_load, Green);
}
