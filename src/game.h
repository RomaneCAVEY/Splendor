#ifndef __GAME_H__
#define __GAME_H__


#include "builder.h"
#include "token.h"
#include "color.h"
#include "second_builder.h"
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef MAX_BUILDERS_AVAILABLE_PER_LVL
#define MAX_BUILDERS_AVAILABLE_PER_LVL 3
#endif


 struct builder_stack{
    struct builder_t* stack[MAX_BUILDERS];
    int nbr_stack;
};

 /*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct player player, struct builder_t* builder );

/**
    Pay the builder with the tokens of the player
*/
int token_pay(struct builder_t * builder, struct player players[NB_PLAYERS], int current_player);



void remove_token(struct player players[NB_PLAYERS] , struct token_t *token, int current_player);
/* Pay the builder game_builder[index] with the tokens of the players current_player
*/
void pay(struct player players[NB_PLAYERS], int index, int current);


/* Pick a token in the market, add in the player's token list, and remove it from the market
*/
void pick_a_token(int current_player, struct player players[NB_PLAYERS], int a);

#endif