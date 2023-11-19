#include "builder.h"
#include "token.h"
#include "color.h"
#include "manipulation.h"
#include "player.h"
#include "game.h"
#include "player.h"
#include "second_token.h"
#include "second_builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SEED 0
#define MAX_TURN 40
#define NB_MIN_PARAM 1
#define NB_PLAYERS 2


struct player players[NB_PLAYERS]; 

int test_player(){ 
    struct player * player;
    int rang=get_random_player(NB_PLAYERS, players);
    player=players[rang];
    printf(" adress of player 1: %p", &player);
    player= [next_player(NB_PLAYERS, players, rang)]
    printf(" adress of player 2: %p", &player);
    return 1;    
}