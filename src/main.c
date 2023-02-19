#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "block.h"
#include "username.h"
#include "memory.h"
#include "storage.h"
#include "date_time.h"
#include "battery.h"

void update_data(unsigned long secs_passed) {
	update_memory(secs_passed);
	update_storage(secs_passed);
	update_date_time(secs_passed);
	update_battery(secs_passed);
}

void create_bar() {
	create_starting_block();
	show_username();
	show_memory();
	show_storage();
	show_date_time();
	show_battery();
	create_ending_block();
}

int main(int argc, char *argv[]) {
	printf("{\"version\":1}\n[\n");
	initialize_username();
	update_data(0);
	for (int i = 0; i < 4; i++) {
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
