#ifndef __GAME_H__
#define __GAME_H__


#include "guild.h"
#include"market.h"
#include "player.h"
#include "second_token.h"
#include "token.h"
#include "power.h"
#include "color.h"

#include "set.h"
#include <stdio.h>
#include <time.h>
#include <string.h>



 struct builder_stack{
    struct builder_t* stack[MAX_BUILDERS];
    int nbr_stack;
};

 /*return NULL if the player can't pay for a buider
 return 4 if he can use only his own builders
 return 1 if he can pay*/
int possibility_token_pay(struct player player, struct builder_t* builder );

/**
    Pay the builder with the tokens and th builders of the player
*/
int token_pay(struct builder_t * builder, struct player players[NB_PLAYERS], int current_player);



void remove_token(struct player players[NB_PLAYERS] , struct token_t *token, int current_player);
/* Pay the builder game_builder[index] with the tokens of the players current_player
*/
void pay(struct player players[NB_PLAYERS], int index, int current);


/* Pick a token in the market, add in the player's token list, and remove it from the market
*/
void pick_tokens(int current_player, struct player players[NB_PLAYERS], int index);

#endif