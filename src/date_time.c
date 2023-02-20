#include <stddef.h>
#include <stdio.h>
#include <time.h>

#include "date_time.h"
#include "block.h"
#include "color.h"

static struct tm _time;
static char _time_meridiem = 'A';
static const char *_time_icons[] = { "󱑊", "󱐿", "󱑀", "󱑁", "󱑂", "󱑃", "󱑄", "󱑅", "󱑆", "󱑇", "󱑈", "󱑉" };
static const char *_time_icon;

void update_date_time(size_t secs_passed) {
	if (secs_passed % 59 == 0) {
		time_t t = time(NULL);
		_time = *localtime(&t);
	}
	if (secs_passed % 1801 == 0) {
		if (_time.tm_hour < 12) {
			_time_icon = _time_icons[_time.tm_hour];
			_time_meridiem = 'A';
		} else {
			_time_icon = _time_icons[_time.tm_hour % 12];
			_time_meridiem = 'P';
		}
	}
}

static const char* _months[] = { "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };
static const char* _days_of_week[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

static void _show_time() {
	printf("%02d:%02d%cM", _time.tm_hour <= 12 ? _time.tm_hour : (_time.tm_hour - 1), _time.tm_min, _time_meridiem);
}

static void _show_date() {
	printf("%d %s %s", _time.tm_mday, _months[_time.tm_mon], _days_of_week[_time.tm_wday]);
}

void show_date_time() {
	create_function_block("time", _time_icon, &_show_time, Green);
	create_function_block("day", "", &_show_date, DarkYellow);
}
