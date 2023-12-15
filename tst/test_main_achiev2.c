#ifndef  __TEST_H__
#define __TEST_H__

#include "builder.h"
#include "test.h"
#include "token.h"
#include "color.h"
#include "player.h"
#include "game.h"
#include "player.h"
#include "second_token.h"
#include "second_builder.h"
#include "set.h"
#include "stack.h"
#include "permutation.h"
#include "market.h"
#include "guild.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SEED 0

#define MAX_TURN 40
#define NB_MIN_PARAM 1
#define NB_PLAYERS 2


struct player players[NB_PLAYERS];

void test_possibility_token_pay(){
    for(int i = 0; i < NB_PLAYERS; i++){
        players[i] = init_player();
        players[i].index = i;
    }
    struct token_t token1={.s.ressource={2,0,0,0,0}};
    struct token_t token2={.s.ressource={1,1,0,0,0}};
    players[0].player_token[0]=&token1;
    players[0].player_token[1]=&token1;
    printf("%d\n",possibility_token_pay(players[0], create_specific_builder()));
}





#endif