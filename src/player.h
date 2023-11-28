#ifndef __PLAYER_H__
#define __PLAYER_H__


#define VICTORY_POINTS 15
#ifndef NB_PLAYERS
#define NB_PLAYERS 2
#endif

#include "builder.h"
#include "token.h"
#include "color.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//Declaration of some variables

struct player{
    struct token_t* player_token[NUM_TOKENS];
    struct builder_t* player_builder[MAX_BUILDERS];
    int points;
    int nbr_token;
    int nbr_builder;
    int index;

};

/**
Init the player and all his parameter
*/
struct player init_player();

/**
Return 1 si one of the player reach the VICTORY_POINTS, else 0
*/
int has_won(struct player players[NB_PLAYERS]);

/**
Give the first player 
*/
int get_random_player(int size );

/**
Give the next player for the next round
*/
int next_player(int size, int current);


/**
Display the builders and tokens of the player
*/
void player_display(struct player player);

/**
Give the winner of the game if he exists
*/
int winner(struct player players[NB_PLAYERS]);

#endif