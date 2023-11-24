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
    struct token_t* playing_board[NUM_TOKENS];
    int permutation[NUM_TOKENS];
};


struct market market;
void init_market();

int market_nbr_token();

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
int tokens_connex(int index, int nbr_token,int current_player);


/*return the number of available tokens*/
int tokens_neighbour(int index);