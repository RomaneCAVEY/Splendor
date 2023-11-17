#include <stdio.h>
#include "color.h"

const char* color_to_string(enum color_t c);

int main(int argc, char* argv[])
{
    enum color_t c=GREEN;
    printf("%s",color_to_string(c));
    return 0;

}







