#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <inttypes.h>

#include "date_time.h"
#include "block.h"
#include "color.h"

static char _time_meridiem;
static uint8_t _time_hour;
static uint8_t _time_minute;
static const char* _time_icons[] = { "󱑊", "󱐿", "󱑀", "󱑁", "󱑂", "󱑃", "󱑄", "󱑅", "󱑆", "󱑇", "󱑈", "󱑉" };
static const char* _months[] = { "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };
static const char* _days_of_week[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
static const char* _time_icon;
static const char* _month;
static const char* _day_of_week;
static uint8_t _day;
static uint16_t _year;

void update_date_time(size_t secs_passed) {
	if (secs_passed % 47 == 0) {
		time_t t = time(NULL);
		struct tm _time = *localtime(&t);
		_time_hour = _time.tm_hour <= 12 ? _time.tm_hour : (_time.tm_hour - 12);
		_time_minute = _time.tm_min;
		_month = _months[_time.tm_mon];
		_day_of_week = _days_of_week[_time.tm_wday];
		_day = _time.tm_mday;
		_year = _time.tm_year + 1900;
	}
	if (secs_passed % 1801 == 0) {
		if (_time_hour < 12) {
			_time_icon = _time_icons[_time_hour];
			_time_meridiem = 'A';
		} else {
			_time_icon = _time_icons[_time_hour % 12];
			_time_meridiem = 'P';
		}
	}
}

static void _show_time() {
	printf("%02d:%02d%cM", _time_hour, _time_minute, _time_meridiem);
}

static void _show_date() {
	printf("%2d %s %u %s", _day, _month, _year, _day_of_week);
}

void show_date_time() {
	create_function_block("time", _time_icon, _show_time, Green);
	create_function_block("day", "", _show_date, DarkCyan);
}
