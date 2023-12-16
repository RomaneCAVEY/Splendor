#include "player.h"
#include "builder.h"
#include <stdio.h>
#include "guild.h"

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
    int random = rand() % size;
    return random;

}

/**
Give the index of the next player for the next round
*/
int next_player(int size, int current) {
    return (current + 1) % size;
}

/**
Display the builders and tokens of the player
*/
void player_display(struct player player){
    printf("This is what the player owns \n");
    printf("=======================================\n");
    for (int i=0; i< player.nbr_token; ++i){
        if(player.player_token[i]){
            token_display(*player.player_token[i], "\n -");
        }
    }
    for (int i=0; i< player.nbr_builder; ++i){
		if(player.player_builder[i]){
        	builder_display(player.player_builder[i], "\n -");
		}
    }
    printf("\n=======================================\n");
}


/** 
Give the winner of the game if he exists
*/
int winner(struct player players[NB_PLAYERS]){
    if (players[0].points >= VICTORY_POINTS) {
        printf("Victory of player 0 with %d points \n", players[0].points);
        return 0;
    }
    if (players[1].points >= VICTORY_POINTS) {
        printf("Victory of player 1 with %d points \n", players[1].points);
        return 0;
    }
    else{
        if (players[1].points>players[0].points){
            printf("Victory of player 1 with %d points \n", players[1].points);
            return 0;
        }
        else{
            printf("Victory of player 0 with %d points \n", players[0].points);
            return 0;
        }
    }
}

