#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>

#include "utils.h"

void print_formatted_size(size_t size) {
	double magnitude;
	uint8_t unit;
	if (size >= 1024.0 * 1024.0 * 1024.0 * 1024.0) {
		magnitude = size / (1024.0 * 1024.0 * 1024.0 * 1024.0);
		unit = 'T';
	} else if (size >= 1024.0 * 1024.0 * 1024.0) {
		magnitude = size / (1024.0 * 1024.0 * 1024.0);
		unit = 'G';
	} else if (size >= 1024.0 * 1024.0) {
		magnitude = size / (1024.0 * 1024.0);
		unit = 'M';
	}  else if (size >= 1024.0) {
		magnitude = size / 1024.0;
		unit = 'K';
	} else {
		printf("%.0fB", size);
		return;
	}
	printf("%.2f%cB", magnitude, unit);
}
