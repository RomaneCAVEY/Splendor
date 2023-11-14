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
    int available_tokens[NUM_TOKENS]; /*Le market est du type [0,1,3,...,NUM_COLORS] avec chaque position correspondant à la couleur d'un jeton*/

};

struct guild{
    int nbr_builder;
    struct builder_t* builder_in_guild[MAX_BUILDERS];

};
    

struct guild init_guild();
struct market init_market();


int guild_nbr_builder();
/*
Init NUM_TOKENS tokens
*/
void init_tokens_from_builers();

/*
    Pay the builder with the tokens of the player
*/
void token_pay(struct builder_t *b,struct player* player);
int market_nbr_token();

void remove_builders_from_guild( struct builder_t* );

struct token_t* adress_token_from_builders(int i);

int is_market_available_tokens(int a );

void change_market_available_tokens(int a,int b);

int is_guild_builder_in_guild(int i);

struct builder_t* guild_builder_in_guild(int index);



void remove_token(struct token_t* tab[], const struct token_t token);
#endif