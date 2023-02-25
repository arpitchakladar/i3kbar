#pragma once

enum Color {
	Black = 0,
	DarkRed = 1,
	DarkGreen = 2,
	DarkYellow = 3,
	DarkBlue = 4,
	DarkMagenta = 5,
	DarkCyan = 6,
	LightGrey = 7,
	DarkGrey = 8,
	Red = 9,
	Green = 10,
	Yellow = 11,
	Blue = 12,
	Magenta = 13,
	Cyan = 14,
	White = 15,
	Background = 16,
	Foreground = 17
};

const char* get_color_hex(enum Color);
