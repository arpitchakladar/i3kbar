#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>

#include "utils.h"

void format_size(size_t size) {
	double magnitude;
	uint8_t unit;
	if (size >= 1024ul * 1024ul * 1024ul * 1024ul) {
		magnitude = size / (1024ul * 1024ul * 1024ul * 10ul);
		unit = 'T';
	} else if (size >= 1024ul * 1024ul * 1024ul) {
		magnitude = size / (1024ul * 1024ul * 10ul);
		unit = 'G';
	} else if (size >= 1024ul * 1024ul) {
		magnitude = size / (1024ul * 10ul);
		unit = 'M';
	}  else if (size >= 1024ul) {
		magnitude = size / 10ul;
		unit = 'K';
	} else {
		magnitude = size * 100ul;
		unit = ' ';
	}
	printf("%.2f%cB", magnitude / 102ul, unit);
}
