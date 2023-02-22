#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "network.h"
#include "block.h"
#include "color.h"
#include "utils.h"

#define PING_SERVER_IP 0x08080808;

static char _interface_carrier_file_path[38] = "/sys/class/net/";
static char _interface_name[16];
static const char* _web_icons[] = { "󰖟 󰈂", "󰖟 󰈁" };
static const char* _web_icon;

void initialize_network() {
	_web_icon = _web_icons[0];
	FILE* net_route_file_ptr = fopen("/proc/net/route", "r");
	fseek(net_route_file_ptr, 128, SEEK_SET);
	char current_char;
	size_t i = 0;
	size_t line_start = 128;
	size_t line_number = 0;
	size_t column_number = 0;
	size_t i2 = 0;
	int copy = 0;
	for (;;) {
		current_char = fgetc(net_route_file_ptr);
		if (current_char == EOF) {
			break;
		} else if (copy) {
			if (current_char == '\t') {
				break;
			} else {
				_interface_name[i2++] = current_char;
			}
		} else {
			switch (current_char) {
				case '\n':
					line_start = i + 1;
					line_number++;
					column_number = 0;
					i2 = 0;
					break;

				case '\t':
					column_number++;
					i2 = 0;
					break;

				default:
					if (column_number == 1) {
						if (current_char == '0') i2++;
						if (i2 >= 8) {
							copy = 1;
							i2 = 0;
							fseek(net_route_file_ptr, line_start, SEEK_SET);
						}
					}
			}
		}
		i++;
	}
	fclose(net_route_file_ptr);
	_interface_name[i2] = '\0';
	strcat(strcat(_interface_carrier_file_path, _interface_name), "/carrier");
}

void update_network(size_t secs_passed) {
	if (secs_passed % 37 == 0) {
		FILE *network_status_file = fopen(_interface_carrier_file_path, "r");
		_web_icon = _web_icons[fgetc(network_status_file) - '0'];
		fclose(network_status_file);
	}
}

void show_network() {
	create_text_block("network", _web_icon, _interface_name, Blue);
}
