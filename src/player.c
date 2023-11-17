#include "player.h"
#include "builder.h"
#include "token.h"

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
int has_won(struct player player1, struct player player2) {
    if (player1.points >= VICTORY_POINTS || player2.points >= VICTORY_POINTS) {
        return 1;
    }
    return 0;
}

/**
Give the first player 
*/
struct player * get_random_player(int size, struct player players[]) {
    srand(time(NULL));
    int random = rand() % size;
    return & players[random];

}

/**
Give the next player for the next round
*/
struct player * next_player(int size, struct player players[], struct player * current) {
    return & players[((current -> index) + 1) % size];
}


void player_display(struct player player){
    for (int i=0; i< player.nbr_token; ++i){
        token_display(*player.player_token[i], "-");
    }
    for (int i=0; i< player.nbr_builder; ++i){
        builder_display(player.player_builder[i], "-");
    }
}