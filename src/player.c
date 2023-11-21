#include "player.h"
#include "builder.h"
#include "token.h"
#include <stdio.h>


/**
Init the player and all his parameter
*/
struct player init_player() {
    struct player new_player = {};
    return new_player;

}

/**
Return 1 si one of the player reach the VICTORY_POINTS, else 0
*/
int has_won(struct player players[NB_PLAYERS]) {
    for (int i=0; i<NB_PLAYERS; ++i){
        if (players[i].points >= VICTORY_POINTS) {
            return 1;
        }
    }
    return 0;
}

/**
Give the index of the player in players
*/
int get_random_player(int size) {
    srand(time(NULL));
    int random = rand() % size;
    return random;

}

/**
Give the index of the next player for the next round
*/
int next_player(int size, int current) {
    return (current + 1) % size;
}


void player_display(struct player player){
    for (int i=0; i< player.nbr_token; ++i){
        token_display(*player.player_token[i], "\n -");
    }
    for (int i=0; i< player.nbr_builder; ++i){
        builder_display(player.player_builder[i], "\n -");
    }
}