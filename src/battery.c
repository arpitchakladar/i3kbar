#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>

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

void update_battery(size_t secs_passed) {
	if (secs_passed % 31 == 0) {
		FILE *battery_percentage_file = fopen("/sys/class/power_supply/BAT0/capacity", "r");
		size_t l = fread(_battery_percentage, sizeof(char), 4, battery_percentage_file);
		_battery_percentage[l - 1] = '%';
		_battery_percentage[l--] = '\0';
		fclose(battery_percentage_file);
		FILE *battery_charging_state_file = fopen("/sys/class/power_supply/AC/online", "r");
		uint8_t battery_charging_state = fgetc(battery_charging_state_file) - '0';
		fclose(battery_charging_state_file);
		size_t i = 1;
		if (l != 1) {
			i = _battery_percentage[l - 2] - '0';
		}
		_battery_icon = _battery_icons[i + battery_charging_state * 10];
	}
}

void show_battery() {
	create_text_block("battery", _battery_icon, _battery_percentage, Cyan);
}
#endif
