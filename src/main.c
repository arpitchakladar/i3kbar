#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "block.h"
#include "username.h"
#include "memory.h"

int main(int argc, char *argv[]) {
	printf("{\"version\":1}\n[\n");
	while (1) {
		create_starting_block();
		show_username();
		show_memory();
		create_ending_block();
	}
	return EXIT_SUCCESS;
}
