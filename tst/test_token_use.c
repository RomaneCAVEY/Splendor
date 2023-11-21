#include "builder.h"
#include "token.h"
#include "color.h"
#include "player.h"
#include "game.h"
#include "player.h"
#include "second_token.h"
#include "second_builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct token_t create_simple_token(enum color_t c);
void token_display(struct token_t t, const char* prefix);

int main (int argc, char* argv[]){
    printf ("this is a test: \n");
    enum color_t c= GREEN;
    struct token_t t=create_simple_token(c);
    const char* prefix= "-";
    token_display(t,prefix);
    return 0;

}