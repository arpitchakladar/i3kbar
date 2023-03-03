#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>

#include "utils.h"

void print_formatted_size(size_t size) {
	double magnitude;
	char unit;
	if (size >= 1024.0 * 1024.0 * 1024.0 * 1000) {
		magnitude = size / (1024.0 * 1024.0 * 1024.0 * 1024.0);
		unit = 'T';
	} else if (size >= 1024.0 * 1024.0 * 1000) {
		magnitude = size / (1024.0 * 1024.0 * 1024.0);
		unit = 'G';
	} else if (size >= 1024.0 * 1000) {
		magnitude = size / (1024.0 * 1024.0);
		unit = 'M';
	}  else if (size >= 1000) {
		magnitude = size / 1024.0;
		unit = 'K';
	} else {
		printf("%6.2f B", (double) size);
		return;
	}
	printf("%6.2f%cB", magnitude, unit);
}
