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


void init_market() {
    market.nbr_token = NUM_TOKENS;
    /*init the playing_board*/
    srand(SEED);
    int tokens_available[NUM_TOKENS]={};
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        int a= rand() % NUM_TOKENS;
        while (!tokens_available[a]){
            a= rand() % NUM_TOKENS;
        }
        market.playing_board[i]= token_get_adress(a);
        tokens_available[a]=1;
    }
    /*permutation is a permutation of the cases , we have to fill it in that order when we push a token in the market*/
     for (unsigned int i=0; i< NUM_TOKENS; i++){
        int a= rand() % NUM_TOKENS;
        while (!market.permutation[i]){
            a= rand() % (NUM_TOKENS-1)+1;
        }

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
            token_display( *market.playing_board[i], " \n voici le token suivant");
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

