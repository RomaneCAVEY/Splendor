#include <stdio.h>
#include <string.h>
#include "color.h"

const char* str_color[]={"BLACK","BLUE","GREEN","RED","WHITE","GOLD","PEARL","AQUAMARINE","OCTARINE","CHESTNUT"};
const char* str_color_short[]={"K","B","G","R","W","G","P","A","O","C"};

const char* color_to_string(enum color_t c)
{
    
    return str_color[c];

}

const char* color_to_short_string(enum color_t c)
{
    return str_color_short[c];
}
