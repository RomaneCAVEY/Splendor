#include "color.h"
#include <stdio.h>
#include <string.h>

const char* color_string[]={
"BLACK",
"BLUE",
"GREEN",
"RED",
"WHITE",
"GOLD",
"PEARL",
"AQUAMARINE",
"OCTARINE",
"CHESTNUT"};


const char* color_short_string[]={
    "K",
"B",
"G",
"R",
"W",
"GD",
"P",
"A",
"O",
"C"};

const char* color_to_string(enum color_t c){
    if (c > MAX_COLORS){
        return "??????????????";
        }

    return color_string[c];   

}

const char* color_to_short_string(enum color_t c){
    if (c > MAX_COLORS){
        return "?";
        }
    return color_short_string[c];
}
