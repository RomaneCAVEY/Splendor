#ifndef __GAME_H__
#define __GAME_H__


#include "token.h"
#include "builder.h"
#include "token.h"
#include "color.h"
#include "second_builder.h"
#include "manipulation.h"
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

/**
    Pay the builder with the tokens of the player
*/
void token_pay(struct builder_t *b,struct player* player);
int market_nbr_token();

void remove_builders_from_guild( struct builder_t* );

void remove_token_from_market(struct token_t* token);

struct token_t* adress_token_from_builders(int i);

int is_guild_builder_in_guild(int i);

struct builder_t* guild_builder_in_guild(int index);


struct token_t* token_in_market_is_available(int i);
void add_token_to_market(struct token_t* token); 
void remove_token(struct token_t* tab[], const struct token_t token);
#endif