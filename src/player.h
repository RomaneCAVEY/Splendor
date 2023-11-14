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

struct player init_player();

int has_won(struct player, struct player);



struct player* get_random_player(int size,struct player players[] );

struct player* next_player(int size, struct player players[], struct player* current );

#endif