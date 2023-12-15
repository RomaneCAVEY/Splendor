#include "favor.h"
#include "guild.h"


//The player can renew the builders from a specific level in  the guild
void builder_guild_renew(int level_choosen, struct guild* guild ) {
    struct builder_t*  stockage[MAX_BUILDERS_AVAILABLE_PER_LVL]={};
    int index=0;
    for (int i=0; i<MAX_BUILDERS; ++i) {
        if (guild->builder_available[i]){
            if ((builder_level(guild->builder_available[i])==level_choosen) && (index<MAX_BUILDERS_AVAILABLE_PER_LVL)){
                if(guild->stack[level_choosen].nb>0){
                struct builder_t* builder_to_add= stack_pop(&guild->stack[level_choosen]);
                stockage[index]=guild_available_builder(i, guild);
                guild->builder_available[i]=builder_to_add;
				++index;
                }
            }
        }
    }
    for (int i=0; i<MAX_BUILDERS_AVAILABLE_PER_LVL; ++i) {
        if (stockage[i]) {
            stack_push(guild->stack,stockage[i]);
        }
    }   
}

//The player can use his favor to take one of the many tokens available on the market
int pick_any_token_in_market(int current_player, struct player players[NB_PLAYERS], int a, struct market* market,struct guild *guild) { //(int a) is used in the fonction pick_token in game.c 
    int random_index=rand()%NUM_TOKENS;
    int counter=0;
    if (market->nbr_token>0) {
        while ((market->playing_board[random_index]==NULL) && (counter<NUM_TOKENS)) {
            random_index= (random_index + 1) % NUM_TOKENS;
            ++counter;
        }
        pick_tokens(current_player, players, a, market,guild);
        return 1;
    }
    return 0;
}

