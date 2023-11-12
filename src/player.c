#include "builder.h"
#include "token.h"
#include "color.h"
#include "manipulation.h"
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

//Declaration of some variables
struct player player1;
struct player player2;


void init_player1(){
    player1.points=0;
    memset(player1.player_token, 0, NUM_TOKENS+MAX_BUILDERS);
    memset(player1.player_builder, 0, MAX_BUILDERS);
}
void init_player2(){
    player2.points=0;
    memset(player2.player_token, 0, NUM_TOKENS+MAX_BUILDERS);
    memset(player2.player_builder, 0, MAX_BUILDERS);
}


int has_won(struct player player1, struct player player2){
    if (player1.points >= VICTORY_POINTS || player2.points >= VICTORY_POINTS){
        return 1;
    }
    return 0;
}



struct player* get_random_player(){
    srand(SEED);
    struct player *player;
    int a= rand() % 2;
    if (a){
        player= & player2;
        return player;
    }
    player= & player1;
    return player;
      
}


void next_player(struct player* current_player){
    if (current_player==&player1){
        current_player=&player2;
    }
    current_player=&player1;
}


