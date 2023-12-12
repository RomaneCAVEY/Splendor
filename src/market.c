#include "market.h"
#include "game.h"
#include "player.h"
#include "second_token.h"
#include "token.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "permutation.h"


struct market market={};


void init_market() {
    market.nbr_token = NUM_TOKENS;
    /*init the playing_board*/
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        market.permutation[i]= make_permutation(i);
    }
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        market.playing_board[i]= token_get_adress(make_permutation(i));
    }
}

struct token_t* make_market(int index){
    return market.playing_board[index];
}

int market_nbr_token() {
    return market.nbr_token;
}
/**
Replace the token j to i, token at place i is free
*/
void market_moove_i_to_j(int i, int j){
    market.playing_board[i]=market.playing_board[j];
    remove_token_from_market(market.playing_board[j]);
    market.nbr_token+=1;
}


void add_token_to_market(struct token_t * token) {
    int i = 0;
     while (market.playing_board[i] && i< NUM_TOKENS) {
        i++;
    }
    market.playing_board[i] = token;
    market.nbr_token = market.nbr_token + 1;

}


int market_token_is_available(int i){
    if(market.playing_board[i]){
        return 1;
    }
    return 0;
}


/* Display the market
*/
void market_display() {
    unsigned int i = 0;
    int square = sqrt(NUM_TOKENS);
    for (i=0; i< NUM_TOKENS; i++){
        if((i%square)==0){
            printf("\n______________________________________________________________________________________________________________________");
            printf("________________________________________________________________________\n\n\n\n");
        }
        if ( market.playing_board[i]){
            token_display( *market.playing_board[i], "|| ");
            if (!is_complex(market.playing_board[i])){
                printf("          ");
            }
        }
        else {
            printf(" ||         empty space           ");
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
   
    if ((index % square != 1) && (market.playing_board[index+1])){
        count += 1;
     }
    
    if ((index % square != 0) && (market.playing_board[index-1])){
        count += 1;
     }

    return count;
}


int tokens_connex(int index, int nbr_token,int current_player, struct player players[NB_PLAYERS]){
    int square = sqrt(NUM_TOKENS);
    int count=1;

    pick_tokens(current_player,players,index);


    if (index<(NUM_TOKENS-square) && market.playing_board[index+square]){
        pick_tokens(current_player,players,index+square);
        count+=1;
    }
    if (count<nbr_token && nbr_token>count){      
        if ((index>square) && market.playing_board[index-square]){
            pick_tokens(current_player,players,index-square);
            count += 1;
        }
    }
    if (count<nbr_token && nbr_token>count){      
        if ((index % square != 1) && (market.playing_board[index+1])){
            pick_tokens(current_player,players,index+1);
            count += 1;
        }
    }
    if (count<nbr_token && nbr_token>count){         
        if ((index % square != 0) && (market.playing_board[index-1])){
            pick_tokens(current_player,players,index-1);
            count += 1;
        }
    }

    return 0;
}


void remove_token_from_market(struct token_t * token){
    for (int i=0; i<NUM_TOKENS; i++){
        if (token == market.playing_board[i]){
            market.playing_board[i] = NULL;
            market.nbr_token-=1;
        }
    }
}