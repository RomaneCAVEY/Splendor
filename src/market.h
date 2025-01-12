#ifndef __MARKET_H__
#define __MARKET_H__

#include "guild.h"
#include "player.h"
#include "second_token.h"
#include "token.h"
#include "permutation.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct market_t{
    int nbr_token;
    struct token_t* playing_board[NUM_TOKENS];
    int permutation[NUM_TOKENS];
};
/**
Init the tokens of the market with the permutation given
*/
void init_market(struct market_t* market);


/**
Give the number of token available in the market
*/
int market_nbr_token(struct market_t* market);

/**
Remove the token from the market
*/
void remove_token_from_market(struct token_t * token, struct market_t* market);

/*add token to the market in the right order from the beginning*/
void add_token_to_market(struct token_t * token, struct market_t* market);

/* Display the market
*/
void market_display(struct market_t* market);

/* Return the adress of the token in the market at the place i
*/
struct token_t * token_in_market_is_available(int i, struct market_t* market);


/*return the number of available tokens*/
int tokens_neighbour(int index, struct market_t* market);

/**
Replace the token j to i, token at place i is free
*/
void market_moove_i_to_j(int i, int j, struct market_t* market);


/**
Give the token at the index index of the market (perutation order)
*/
struct token_t* make_market(int index, struct market_t* market);

/**
Put the token at place i to the empty space of index i in the market 
*/
void market_replace(int i, int j, struct market_t* market);

/*if there are enought connex tokens, current_player takes it*/
int tokens_connex(int index, int nbr_token,int current_player, struct player players[NB_PLAYERS], struct market_t* market_t,struct guild_t* guild);


#endif