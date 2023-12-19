#include "color.h"
#include"second_color.h"
#include <stdio.h>
#include "ansi_color.h"
#include <string.h>

const char * color_string[] = {
"BLACK",
"BLUE",
"GREEN",
"RED",
"WHITE",
"GOLD",
"PEARL",
"AQUAMARINE",
"OCTARINE",
"CHESTNUT"
};

const char * color_short_string[] = {
"K",
"B",
"G",
"R",
"W",
"GD",
"P",
"A",
"O",
"C"
};

const char * prefix_color_display[MAX_COLORS] = {
HBLK,
BLU,
GRN,
RED,
COLOR_RESET,
COLOR_RESET,
COLOR_RESET,
COLOR_RESET,
COLOR_RESET,
COLOR_RESET,
};

const char* prefix_color(enum color_t c){
	return prefix_color_display[c];
}

const char * color_to_string(enum color_t c) {
	if (c > MAX_COLORS) {
		return "??????????????";
}

	return color_string[c];

}

const char * color_to_short_string(enum color_t c) {
	if (c > MAX_COLORS) {
		return "?";
	}
	return color_short_string[c];
}

