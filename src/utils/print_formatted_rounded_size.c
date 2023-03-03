#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>

#include "utils.h"

void print_formatted_rounded_size(size_t size) {
	size_t magnitude;
	char unit;
	if (size >= 1024ul * 1024ul * 1024ul * 1024ul) {
		magnitude = size / (1024ul * 1024ul * 1024ul * 1024ul);
		unit = 'T';
	} else if (size >= 1024ul * 1024ul * 1024ul) {
		magnitude = size / (1024ul * 1024ul * 1024ul);
		unit = 'G';
	} else if (size >= 1024ul * 1024ul) {
		magnitude = size / (1024ul * 1024ul);
		unit = 'M';
	}  else if (size >= 1024ul) {
		magnitude = size / 1024ul;
		unit = 'K';
	} else {
		printf("%4zu B", size);
		return;
	}
	printf("%4zu%cB", magnitude, unit);
}
