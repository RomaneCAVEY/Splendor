#include "builder.h"
#include "token.h"
#include "color.h"
#include "manipulation.h"
#include "player.h"
#include "sgame.h"
#include "second_token.h"
#include "second_builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




/*int main (int argc, char* argv[]){
    printf ("this is a test");
    enum color_t c= GREEN;
    struct token_t t=create_simple_token(c);
    const char* prefix= "-";
    token_display(t,prefix);
    return 0;
}*/

int main (int argc, char* argv[])
{
    struct token_t* t[NUM_TOKENS]=
    struct token_t t2[NUM_TOKENS];
    for (int i = 1 ; i < NUM_TOKENS ; ++i){
        t[i]=&t2[i];
    }
    t[0]={{0,0,0,0,0,0,0,0,0,0}};
    return 0;
}