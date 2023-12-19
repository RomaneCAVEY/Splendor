#include "favor.h"
#include "builder.h"
#include "guild.h"
#include "market.h"
#include "token.h"


//The player can renew the builders from a specific level in  the guild
void builder_guild_renew(int level_choosen, struct guild_t* guild ) {
	printf(BHRED"The player have the following power: builder_guild_renew \n" COLOR_RESET);
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
int pick_any_token_in_market(int current_player, struct player players[NB_PLAYERS], int a, struct market_t* market,struct guild_t *guild) { //(int a) is used in the fonction pick_token in game.c 
    printf(BHRED"The player have the following power: pick_any_token_in_market \n" COLOR_RESET);
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

void execute_favors(int current_player, struct player players[NB_PLAYERS],struct market_t *market,struct guild_t *guild,int level_choosen){
	if (players[current_player].favor_nbr){
		srand(0);
		int random=rand();
		if (random%2){
			
			builder_guild_renew(level_choosen, guild) ;
		}
		else{
			if (market->nbr_token){
				int c=0;
				while(c<NUM_TOKENS && !token_in_market_is_available(random+c, market)){
					c++;
				}
			pick_any_token_in_market(current_player,players, ((c+random)%NUM_TOKENS), market,guild);
			}
		}

	}

}