#ifndef __PLAYER_H__
#define __PLAYER_H__


#define VICTORY_POINTS 40

#include "builder.h"
#include "token.h"
#include "color.h"
#include "manipulation.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//Declaration of some variables

struct player{
    struct token_t* player_token[NUM_TOKENS+MAX_BUILDERS];
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
int has_won(struct player, struct player);



/**
Give the first player 
*/
struct player* get_random_player(int size,struct player players[] );

/**
Give the next player for the next round
*/
struct player* next_player(int size, struct player players[], struct player* current );


/**
Display the builders and tokens of the player
*/
void player_display(struct player player);

#endif