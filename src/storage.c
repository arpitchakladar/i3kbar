#include <stddef.h>
#include <sys/statvfs.h>

#include "storage.h"
#include "block.h"
#include "utils.h"
#include "color.h"

static size_t _size;

static void _show_storage() {
	format_size(_size);
}

void update_storage(size_t secs_passed) {
	if (secs_passed % 61 == 0) {
		struct statvfs info;
		statvfs("/", &info);
		_size = info.f_bavail * info.f_bsize;
	}
}

void show_storage() {
	create_function_block("storage", "", &_show_storage, DarkGreen);
}
