#include <stdio.h>
#include "color.h"
#include "test.h"

const char* color_to_string(enum color_t c);

int main(int argc, char* argv[])
{
    test_token();
    test_builder();
    test_market();
    test_game();
    test_display();
    test_player();
    printf("all test passed!!!!!!!!!!!!!!!!!");
    return 0;

}







