#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>
#include <ctype.h>

#include "battery.h"
#include "color.h"
#include "block.h"

#ifndef DESKTOP_MODE
static char _battery_percentage[5];
static const char* _battery_icons[] = {
	"󰁹", "󰁺", "󰁻", "󰁼", "󰁽", "󰁾", "󰁿", "󰂀", "󰂁", "󰂂", // discharging
	"󰂅", "󰢜", "󰂆", "󰂇", "󰂈", "󰢝", "󰂉", "󰢞", "󰂊", "󰂋" // charging
};
static const char *_battery_icon;

void initialize_battery() {
	_battery_percentage[4] = '\0';
	_battery_percentage[3] = '%';
}

void update_battery(size_t secs_passed) {
	if (secs_passed % 31 == 0) {
		FILE* battery_percentage_file = fopen("/sys/class/power_supply/BAT0/capacity", "r");
		uint8_t l = 0;
		for (;;) {
			char current_character = fgetc(battery_percentage_file);
			if (isdigit(current_character)) {
				_battery_percentage[l++] = current_character;
			} else {
				break;
			}
		}
		fclose(battery_percentage_file);
		FILE* battery_charging_state_file = fopen("/sys/class/power_supply/AC/online", "r");
		uint8_t battery_charging_state = fgetc(battery_charging_state_file) - '0';
		fclose(battery_charging_state_file);
		uint8_t i = 1;
		if (l > 1) {
			i = _battery_percentage[l - 2] - '0';
		}
		_battery_icon = _battery_icons[i + battery_charging_state * 10];
		if (l < 3) {
			uint8_t shift_by = 3 - l;
			do {
				l--;
				_battery_percentage[l + shift_by] = _battery_percentage[l];
			} while (l > 0);
			do {
				_battery_percentage[--shift_by] = ' ';
			} while (shift_by > 0);
		}
	}
}

void show_battery() {
	create_text_block("battery", _battery_icon, _battery_percentage, Cyan);
}
#endif
