#pragma once

enum Color {
	Background = 0,
	Foreground = 1,
	Black = 2,
	DarkGrey = 3,
	DarkRed = 4,
	Red = 5,
	DarkGreen = 6,
	Green = 7,
	DarkYellow = 8,
	Yellow = 9,
	DarkBlue = 10,
	Blue = 11,
	DarkMagenta = 12,
	Magenta = 13,
	DarkCyan = 14,
	Cyan = 15,
	LightGrey = 16,
	White = 17
};

const char* get_color_hex(enum Color);
