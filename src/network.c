#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#include "network.h"
#include "block.h"
#include "color.h"
#include "utils.h"

static char _interface_carrier_file_path[38] = "/sys/class/net/";
static char _received_bytes_file_path[50] = "/sys/class/net/";
static char _transmitted_bytes_file_path[50] = "/sys/class/net/";

static char _interface_name[16];
static size_t _received_bytes_per_second = 0;
static size_t _transmitted_bytes_per_second = 0;

static size_t _received_bytes;
static size_t _transmitted_bytes;
static clock_t _clock_cycle;

static const char* _web_icons[] = { "󰖟 󰈂", "󰖟 󰈁" };
static const char* _web_icon;

static size_t _read_number_from_file(const char *file_name) {
	FILE* file = fopen(file_name, "r");
	char current_char;
	size_t number = 0;
	for (;;) {
		current_char = fgetc(file);
		if (isdigit(current_char)) {
			number = number * 10 + (current_char - '0');
		} else {
			break;
		}
	}
	fclose(file);
	return number;
}

void initialize_network() {
	_web_icon = _web_icons[0];
	FILE* net_route_file_ptr = fopen("/proc/net/route", "r");
	fseek(net_route_file_ptr, 128, SEEK_SET);
	char current_char;
	size_t i = 0;
	size_t line_start = 128;
	size_t column_number = 0;
	size_t j = 0;
	bool copy = false;
	for (;;) {
		current_char = fgetc(net_route_file_ptr);
		if (current_char == EOF) {
			break;
		} else {
			switch (current_char) {
				case '\n':
					if (copy) {
						goto end;
					}
					line_start = i + 1;
					column_number = 0;
					j = 0;
					break;

				case '\t':
					if (copy) {
						goto end;
					}
					column_number++;
					j = 0;
					break;

				default:
					if (copy) {
						_interface_name[j++] = current_char;
					} else if (column_number == 1) {
						if (current_char == '0') j++;
						if (j >= 8) {
							copy = true;
							j = 0;
							fseek(net_route_file_ptr, line_start, SEEK_SET);
						}
					}
			}
		}
		i++;
	}
end:
	fclose(net_route_file_ptr);
	_interface_name[j] = '\0';
	strcat(strcat(_interface_carrier_file_path, _interface_name), "/carrier");
	strcat(strcat(_received_bytes_file_path, _interface_name), "/statistics/rx_bytes");
	strcat(strcat(_transmitted_bytes_file_path, _interface_name), "/statistics/tx_bytes");
	_received_bytes = _read_number_from_file(_received_bytes_file_path);
	_transmitted_bytes = _read_number_from_file(_transmitted_bytes_file_path);
	_clock_cycle = clock();
}

void update_network(size_t secs_passed) {
	if (secs_passed % 37 == 0) {
		FILE *network_status_file = fopen(_interface_carrier_file_path, "r");
		_web_icon = _web_icons[fgetc(network_status_file) - '0'];
		fclose(network_status_file);
	}
	if (secs_passed % 7 == 1) {
		size_t clock_cycles = _clock_cycle;
		size_t previous_received_bytes = _received_bytes;
		size_t previous_transmitted_bytes = _transmitted_bytes;
		_received_bytes = _read_number_from_file(_received_bytes_file_path);
		_transmitted_bytes = _read_number_from_file(_transmitted_bytes_file_path);
		_clock_cycle = clock();
		clock_cycles = _clock_cycle - clock_cycles;
		_received_bytes_per_second = (CLOCKS_PER_SEC * (_received_bytes - previous_received_bytes)) / clock_cycles;
		_transmitted_bytes_per_second = (CLOCKS_PER_SEC * (_transmitted_bytes - previous_transmitted_bytes)) / clock_cycles;
	}
}

static void _show_network() {
	printf("%s  ", _interface_name);
	print_formatted_size(_received_bytes_per_second);
	printf("/s  ");
	print_formatted_size(_transmitted_bytes_per_second);
	printf("/s");
}

void show_network() {
	create_function_block("network", _web_icon, _show_network, Blue);
}
