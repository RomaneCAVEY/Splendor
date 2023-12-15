#ifndef __MARKET_H__
#define __MARKET_H__

#include "token.h"
#include "player.h"


struct market{
    int nbr_token;
    struct token_t* playing_board[NUM_TOKENS];
    int permutation[NUM_TOKENS];
};
/**
Init the tokens of the market with the permutation given
*/
void init_market(struct market* market);


/**
Give the number of token available in the market
*/
int market_nbr_token(struct market* market);

/**
Remove the token from the market
*/
void remove_token_from_market(struct token_t * token, struct market* market);

/*add token to the market in the right order from the beginning*/
void add_token_to_market(struct token_t * token, struct market* market);

/* Display the market
*/
void market_display(struct market* market);

/* Return the adress of the token in the market at the place i
*/
struct token_t * token_in_market_is_available(int i, struct market* market);

/*if there are enought connex tokens, current_player takes it*/
int tokens_connex(int index, int nbr_token,int current_player, struct player players[NB_PLAYERS], struct market* market);


/*return the number of available tokens*/
int tokens_neighbour(int index, struct market* market);


/**
Give the token at the index index of the market (perutation order)
*/
struct token_t* make_market(int index, struct market* market);

/**
Put the token at place i to the empty space of index i in the market 
*/
void market_replace(int i, int j, struct market* market);


#endif