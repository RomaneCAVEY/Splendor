#ifndef __MARKET_H__
#define __MARKET_H__

#include "token.h"
#include "player.h"

struct market{
    int nbr_token;
    struct token_t* playing_board[NUM_TOKENS];
    int permutation[NUM_TOKENS];
};


void init_market();

int pick_any_token_in_market(int current_player, struct player players[NB_PLAYERS], int a);

int market_nbr_token();

/**
Remove the token from the market
*/
void remove_token_from_market(struct token_t * token);

/*add token to the market in the right order from the beginning*/
void add_token_to_market(struct token_t * token);

/* Display the market
*/
void market_display();

/* Return the adress of the token in the market at the place i
*/
struct token_t * token_in_market_is_available(int i);

/*if there are enought connex tokens, current_player takes it*/
int tokens_connex(int index, int nbr_token,int current_player, struct player players[NB_PLAYERS]);


/*return the number of available tokens*/
int tokens_neighbour(int index);


/**
Give the token at the index index of the market (perutation order)
*/
struct token_t* make_market(int index);

/**
Put the token at place i to the empty space of index i in the market 
*/
void market_replace(int i, int j);


#endif