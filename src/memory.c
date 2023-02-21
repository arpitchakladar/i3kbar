#include <stddef.h>
#include <stdio.h>
#include <sys/sysinfo.h>

#include "memory.h"
#include "block.h"
#include "utils.h"
#include "color.h"

static size_t _free_ram;
static size_t _total_ram;

static void _show_memory() {
	print_formatted_size(_free_ram);
	printf(" of ");
	print_formatted_size(_total_ram);
}

void update_memory(size_t secs_passed) {
	if (secs_passed % 17 == 0) {
		struct sysinfo info;
		sysinfo(&info);
		_free_ram = info.freeram;
		_total_ram = info.totalram;
	}
}

void show_memory() {
	create_function_block("memory", "", _show_memory, DarkYellow);
}
