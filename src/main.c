#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "block.h"
#include "username.h"
#include "memory.h"
#include "storage.h"

void create_bar() {
	create_starting_block();
	show_username();
	show_memory();
	show_storage();
	create_ending_block();
}

int main(int argc, char *argv[]) {
	printf("{\"version\":1}\n[\n");
	for (int i = 0; i < 4; i++) {
		create_bar();
	}
	while (1) {
		create_bar();
		sleep(1);
	}
	return EXIT_SUCCESS;
}
