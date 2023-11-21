#include "second_token.h"
#include "second_builder.h"
#include "token.h"
#include "color.h"
#include "builder.h"  
#include <stdio.h>
#include "game.h"
#include "player.h"
#ifndef SEED
  #define SEED 0
#endif


int main(int argc,char* argv[])
{
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
    printf("Le joueur peut-il payer ?: %d\n",possibility_token_pay(p,make_builder(4)));
    return 0;
}