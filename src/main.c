#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("{\"version\":1}\n[\n");
	while (1) {
		printf("[{\"full_text\":\"HELLO THIS IS ME!\"}],\n");
	}
	return EXIT_SUCCESS;
}
