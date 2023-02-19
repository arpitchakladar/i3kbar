#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "block.h"

int main(int argc, char *argv[]) {
	printf("{\"version\":1}\n[\n");
	while (1) {
		create_starting_block();
		create_block("message1", "Hello World!", "#689d6a");
		create_block("message2", "Hello World!2", "#710dea");
		create_ending_block();
	}
	return EXIT_SUCCESS;
}
