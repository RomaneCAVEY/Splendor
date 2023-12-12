#include "favor.h"

//The player can renew the builders from a specific level in  the guild
void builder_guild_renew(int level_choosen ) {
    struct builder_t*  stockage[3]={};
    int index=0;
    for (int i=0; i<MAX_BUILDERS) {
        if (guild.builder_available[i]){
            if ((guild.builder_available[i]->level==level_choosen) && (index<3)){
                stockage[index]=builder_available[i];
				++index;
            }
        }
    }
    for (int i=0; i<3; ++i) {
        if (stockage[i]!=NULL) {
            push(stockage[i]);
        }
    }   
}

//The player can use his favor to take one of the many tokens available on the market
int pick_any_token_in_market(int current_player, struct player players[NB_PLAYERS], int a) { //(int a) is used in the fonction pick_token in game.c 
    int random_index=rand()%NUM_TOKENS;
    int counter=0;
    if (market.nbr_token>0) {
        while ((market.playing_board[random_index]==NULL) && (counter<NUM_TOKENS)) {
            random_index= (random_index + 1) % NUM_TOKENS;
            ++counter;
        }
        pick_tokens(current_player, players, a);
        return 1;
    }
    return 0;
}

