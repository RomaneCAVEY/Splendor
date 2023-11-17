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

int main(int argc, char* argv[]){   
    
    struct player * player= get_random_player(2, players);
    printf(" adress of player 1: %p", player);
    player=next_player(2, players, player);
    printf(" adress of player 2: %p", player);
    
    }