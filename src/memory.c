#include <stdio.h>
#include <sys/sysinfo.h>

#include "memory.h"
#include "block.h"
#include "utils.h"

static void _show_memory() {
	struct sysinfo info;
	sysinfo(&info);
	format_size(info.freeram);
	printf(" of ");
	format_size(info.totalram);
}

void show_memory() {
	create_function_block("memory", "", &_show_memory, "#d79921");
}
