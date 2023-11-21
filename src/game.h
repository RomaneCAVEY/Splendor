#ifndef __GAME_H__
#define __GAME_H__


#include "token.h"
#include "builder.h"
#include "token.h"
#include "color.h"
#include "second_builder.h"
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

struct market{
    int nbr_token;
    struct token_t* available_tokens[NUM_TOKENS];
};

struct guild{
    int nbr_builder;
    struct builder_t* builder_in_guild[MAX_BUILDERS];

};
    

void init_guild();
void init_market();


int guild_nbr_builder();



/*
Init NUM_TOKENS tokens
*/
void init_tokens_from_builers();

 /*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct player player, struct builder_t* );

/**
    Pay the builder with the tokens of the player
*/
int token_pay(struct builder_t * builder, struct player players[NB_PLAYERS], int current_player);
int market_nbr_token();



void market_display() ;
void remove_builders_from_guild( struct builder_t* );

void remove_token_from_market(struct token_t* token);

struct token_t* adress_token_from_builders(int i);

int is_guild_builder_in_guild(int i);

struct builder_t* guild_builder_in_guild(int index);


struct token_t* token_in_market_is_available(int i);

/* Add token in the market, at the first place where it's free (a cse which points on NULL)
*/
void add_token_to_market(struct token_t* token); 



void remove_token(struct player players[NB_PLAYERS] , struct token_t *token, int current_player);
/* Pay the builder game_builder[index] with the tokens of the players current_player
*/
void pay(struct player players[NB_PLAYERS], int index, int current);


/* Pick a token in the market, add in the player's token list, and remove it from the market
*/
void pick_a_token(int current_player, struct player players[NB_PLAYERS], int a);

#endif