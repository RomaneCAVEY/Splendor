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
#include "test.h"
#ifndef SEED
  #define SEED 0
#endif


int test_init(){
    init_player();
    init_all_tokens();
    init_builders(10);

    printf("====VOICI LES TOKENS DE LA PARTIE====\n");
    for (int i; i < NUM_TOKENS; ++i ){
        token_display(*(make_token(i)),"");
    }
    printf("====VOICI LES BUILDERS DE LA PARTIE====\n");
    for (int i; i < MAX_BUILDERS; ++i ){
        builder_display(make_builder(i),"");
    }   
    printf("Test passed");
    return 0;
}