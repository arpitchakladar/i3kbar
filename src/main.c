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

void update_data(unsigned long secs_passed) {
	update_memory(secs_passed);
	update_storage(secs_passed);
	update_date_time(secs_passed);
	update_battery(secs_passed);
	update_load(secs_passed);
}

void create_bar() {
	start_block();
	show_username();
	show_memory();
	show_load();
	show_storage();
	show_date_time();
	show_battery();
	end_block();
}

int main(int argc, char *argv[]) {
	initialize_bar();
	initialize_username();
	initialize_load();
	update_data(0);
	for (int i = 0; i < 5; i++) {
		create_bar();
	}
	unsigned long secs_passed = 0;
	while (1) {
		create_bar();
		sleep(1);
		update_data(++secs_passed);
	}
	return EXIT_SUCCESS;
}
