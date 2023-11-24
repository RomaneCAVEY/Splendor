#include "game.h"

#include "player.h"

#include "builder.h"
#include "second_builder.h"

#include "second_token.h"

#include "token.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SEED 0


//ROMANE PART
//connex tokens
struct market{
    int nbr_token;
    struct token_t* playing_board[NUM_TOKENS];
    int permutation[NUM_TOKENS];
};

void init_market() {
    market.nbr_token = NUM_TOKENS;
    /*init the playing_board*/
    market.playing_board={};
    srand(SEED);
    int tokens_available[NUM_TOKENS]={};
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        int a= rand() % NUM_TOKENS;
        while (!tokens_available[a]){
            a= rand() % NUM_TOKENS;
        }
        market.playing_board[i]= &all_tockens[a];
        tokens_available[a]=1;
    }
    /*permutation is a permutation of the cases , we have to fill it in that order when we push a token in the market*/
     market.permutation={};
     for (unsigned int i=0; i< NUM_TOKENS; i++){
        int a= rand() % NUM_TOKENS;
        while (!market.permutation[i]){
            a= rand() % (NUM_TOKENS-1)+1;
        }

    }
}

/*Return the number of token connex to the token (himself counts for one)*/
int tokens_neighbour(int index){
    double square= sqrt(NUM_TOKENS);
    int s=square;
    int count=1;
    if (index<(NUM_TOKENS-s) && playing_board[index+s]){
        count+=1;
    }
    if ((index>square) && playing_board[index-s]){
        count+=1;
    }
   
    if ((index % s != 4) && (playing_board[index+1])){
        count+=1;
     }
    
    if ((index % s != 0) && (playing_board[index-1])){
        count+=1;
     }

    return 0;

}

/*if there are enought connex tokens, current_player takes it*/
int tokens_connex(int index, int nbr_token,int current_player){
    double square= sqrt(NUM_TOKENS);
    int s=square;
    if(tokens_neighbour(index)== nbr_token){
        if (index<(NUM_TOKENS-s) && playing_board[index+s]){
            pick_a_token(current_player, players, index+s);
        }
        if ((index>square) && playing_board[index-s]){
            pick_a_token(current_player, players, index-s);
        }
    
        if ((index % s != 4) && (playing_board[index+1])){
            pick_a_token(current_player, players, index+1);
        }
        
        if ((index % s != 0) && (playing_board[index-1])){
            pick_a_token(current_player, players, index-1);
        }

    }
    return 0;

}


/*Add token to the market in the order of the market's permutation*/
void add_token_to_market(struct token_t * token) {
    unsigned int i = 0;
    int index= market.permutation[i]
     while (market.playing_board[index] && i< NUM_TOKENS) {
        i++;
        index=market.permutation[i];
    }
    market.playing_board[market.permutation[i]] = token;
    market.nbr_token+= 1;

}


//CONSTANTIN PART

