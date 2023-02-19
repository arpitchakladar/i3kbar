#include <sys/statvfs.h>

#include "storage.h"
#include "block.h"
#include "utils.h"

static void _show_storage() {
	struct statvfs info;
	statvfs("/", &info);
	format_size(info.f_bavail * info.f_bsize);
}

void show_storage() {
	create_function_block("storage", "", &_show_storage, "#b16286");
}
