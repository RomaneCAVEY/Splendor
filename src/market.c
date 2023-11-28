#include "market.h"
#include "token.h"
#include "builder.h"
#include "token.h"
#include "color.h"
#include "second_builder.h"
#include "second_token.h"
#include "player.h"
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct market market={};


void init_market(int permutation[NUM_TOKENS]) {
    market.nbr_token = NUM_TOKENS;
    /*init the playing_board*/
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        market.permutation[i]= permutation[i];
    }
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        market.playing_board[i]= token_get_adress(permutation[i]);
    }
}



int market_nbr_token() {
    return market.nbr_token;
}



void remove_token_from_market(struct token_t * token){
    for (int i=0; i<NUM_TOKENS; i++){
        if (token== market.playing_board[i]){
            market.playing_board[i] = NULL;
            market.nbr_token-=1;
        }
    }
}

void add_token_to_market(struct token_t * token) {
    int i = 0;
     while (market.playing_board[i] && i< NUM_TOKENS) {
        i++;
    }
    market.playing_board[i] = token;
    market.nbr_token = market.nbr_token + 1;

}

/* Display the market
*/
void market_display() {
    unsigned int i = 0;
    for (i=0; i< NUM_TOKENS; i++){
        if ( market.playing_board[i])
        {
            token_display( *market.playing_board[i], " this token belongs to the market \n");
        }
    }
}

/* Return the adress of the token in the market at the place i
*/
struct token_t * token_in_market_is_available(int i) {
    return market.playing_board[i];
}



/*Return the number of token connex to the token (himself counts for one)*/
int tokens_neighbour(int index){
    int square = sqrt(NUM_TOKENS);
    int count = 1;
    if (index<(NUM_TOKENS-square) && market.playing_board[index+square]){
        count += 1;
    }
    if ((index>square) && market.playing_board[index-square]){
        count += 1;
    }
   
    if ((index % square != 4) && (market.playing_board[index+1])){
        count += 1;
     }
    
    if ((index % square != 0) && (market.playing_board[index-1])){
        count += 1;
     }

    return 0;
}

