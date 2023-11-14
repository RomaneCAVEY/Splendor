#include "player.h"

struct player init_player(){
    struct player new_player ={};
    return new_player;

    
}


int has_won(struct player player1, struct player player2){
    if (player1.points >= VICTORY_POINTS || player2.points >= VICTORY_POINTS){
        return 1;
    }
    return 0;
}



struct player* get_random_player(int size,struct player players[] ){
    srand(time(NULL));
    int random= rand() % size;
    return &players[random];
    
}


struct player* next_player(int size, struct player players[], struct player* current ){
    return &players[((current->index)+1)%size];
}


