#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "block.h"
#include "username.h"
#include "memory.h"
#include "storage.h"
#include "date_time.h"
#include "battery.h"
#include "load.h"
#include "network.h"

void update_data(size_t secs_passed) {
	update_memory(secs_passed); // 17s
	update_storage(secs_passed); // 61s
	update_network(secs_passed); // 37s
	update_date_time(secs_passed); // 47s
	update_load(secs_passed); // 19s
#ifndef DESKTOP_MODE
	update_battery(secs_passed); // 31s
#endif
}

void create_bar() {
	start_block();
	show_username();
	show_memory();
	show_load();
	show_storage();
	show_network();
	show_date_time();
#ifndef DESKTOP_MODE
	show_battery();
#endif
	end_block();
}

int main(int argc, char *argv[]) {
	initialize_bar();
	initialize_username();
	initialize_load();
	initialize_network();
	update_data(0);
	for (size_t i = 0; i < 5; i++) {
		create_bar();
	}
	size_t secs_passed = 0;
	while (1) {
		create_bar();
		sleep(1);
		update_data(++secs_passed);
	}
	return EXIT_SUCCESS;
}
