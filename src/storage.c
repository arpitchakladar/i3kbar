#include <sys/statvfs.h>

#include "storage.h"
#include "block.h"
#include "utils.h"

static struct statvfs _info;

static void _show_storage() {
	format_size(_info.f_bavail * _info.f_bsize);
}

void update_storage(unsigned long secs_passed) {
	if (secs_passed % 61 == 0) {
		statvfs("/", &_info);
	}
}

void show_storage() {
	create_function_block("storage", "", &_show_storage, "#8ec07c");
}
