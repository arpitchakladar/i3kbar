#include <stdio.h>

#include "battery.h"
#include "color.h"
#include "block.h"

static char _battery_percentage[5];
static char _battery_percentage_length;
static char _battery_charging_state;
static const char* _battery_icons[] = {
	"󰁹", "󰁺", "󰁻", "󰁼", "󰁽", "󰁾", "󰁿", "󰂀", "󰂁", "󰂂",
	"󰂅", "󰢜", "󰂆", "󰂇", "󰂈", "󰢝", "󰂉", "󰢞", "󰂊", "󰂋"
};
static const char *_battery_icon;

void update_battery(unsigned long secs_passed) {
	if (secs_passed % 31 == 0) {
		FILE *battery_percentage_file = fopen("/sys/class/power_supply/BAT0/capacity", "r");
		size_t l = fread(_battery_percentage, sizeof(char), 4, battery_percentage_file);
		_battery_percentage[l - 1] = '%';
		_battery_percentage[l] = '\0';
		_battery_percentage_length = l - 1;
		fclose(battery_percentage_file);
		FILE *battery_charging_state_file = fopen("/sys/class/power_supply/AC/online", "r");
		_battery_charging_state = fgetc(battery_charging_state_file) - '0';
		fclose(battery_charging_state_file);
		size_t i = 1;
		if (_battery_percentage_length != 1) {
			i = _battery_percentage[_battery_percentage_length - 2] - '0';
		}
		_battery_icon = _battery_icons[i + _battery_charging_state * 10];
	}
}

void show_battery() {
	create_text_block("battery", _battery_icon, _battery_percentage, DarkGreen);
}
