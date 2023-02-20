#include <stddef.h>
#include <stdio.h>
#include <sys/sysinfo.h>

#include "memory.h"
#include "block.h"
#include "utils.h"
#include "color.h"

static struct sysinfo _info;

static void _show_memory() {
	format_size(_info.freeram);
	printf(" of ");
	format_size(_info.totalram);
}

void update_memory(size_t secs_passed) {
	if (secs_passed % 17 == 0) {
		sysinfo(&_info);
	}
}

void show_memory() {
	create_function_block("memory", "", &_show_memory, DarkBlue);
}
