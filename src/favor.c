#include "favor.h"
#include "builder.h"
#include "guild.h"
#include "market.h"
#include "stack.h"
#include "token.h"
#include <stdio.h>


//The player can renew the builders from a specific level in  the guild
void builder_guild_renew(unsigned int level_choosen, struct guild_t* guild ) {
	printf(BHRED"The player have the following power: builder_guild_renew with the level %d \n" COLOR_RESET,level_choosen);
	printf("The guild before the favor:");
	//guild_display(guild);
    struct builder_t* tmp[MAX_BUILDERS_AVAILABLE_PER_LVL]={};
	//stack_display(guild->stack[level_choosen]);
		if (guild->stack[level_choosen].nb){
		for (int k=0; k< MAX_BUILDERS_AVAILABLE_PER_LVL; k++){
			tmp[k]=guild->builder_available[level_choosen*MAX_BUILDERS_AVAILABLE_PER_LVL+k];
			//builder_display(tmp[k], "fyftr");
		}
		for (int k=0; k< MAX_BUILDERS_AVAILABLE_PER_LVL; k++){
			if (guild->stack[level_choosen].nb>0){
				guild->builder_available[level_choosen*MAX_BUILDERS_AVAILABLE_PER_LVL+k]=stack_pop(&guild->stack[level_choosen]);
			}
			else{
				guild->builder_available[level_choosen*MAX_BUILDERS_AVAILABLE_PER_LVL+k]=NULL;
			}
		}
		//guild_display(guild);
		for (int k=0; k< MAX_BUILDERS_AVAILABLE_PER_LVL; k++){
			if (tmp[k]){
				stack_push(&guild->stack[level_choosen], tmp[k]);
			}
		}
		//stack_display(guild->stack[level_choosen]);
		for (int k=0; k< MAX_BUILDERS_AVAILABLE_PER_LVL; k++){
			if (!guild->builder_available[level_choosen*MAX_BUILDERS_AVAILABLE_PER_LVL+k]){
				if(guild->stack[level_choosen].nb>0){
					guild->builder_available[level_choosen*MAX_BUILDERS_AVAILABLE_PER_LVL+k]=stack_pop(&guild->stack[level_choosen]);
				}
			}
		}
		printf("The guild after the favor:");
		guild_display(guild);
		}
		else{
			printf("Failed of the favor: the builders of the level choosen are already in the guild");
		}

}




//The player can use his favor to take one of the many tokens available on the market
int pick_any_token_in_market(int current_player, struct player players[NB_PLAYERS], struct market_t* market,struct guild_t *guild) { //(int a) is used in the fonction pick_token in game.c 
    printf(BHRED"The player have the following power: pick_any_token_in_market \n" COLOR_RESET);
	int random_index=rand()%NUM_TOKENS;
    int counter=0;
    if (market->nbr_token>0) {
        while ((market->playing_board[random_index]==NULL) && (counter<NUM_TOKENS)) {
            random_index= (random_index + 1) % NUM_TOKENS;
            ++counter;
        }
        pick_tokens(current_player, players,random_index, market,guild);
        return 1;
    }
    return 0;
}

void execute_favors(int current_player, struct player players[NB_PLAYERS],struct market_t *market,struct guild_t *guild,int level_choosen){
	if (players[current_player].favor_nbr>=1){
		players[current_player].favor_nbr-=1;
		srand(0);
		int random=rand();
		if (random%2){
			
			builder_guild_renew(level_choosen, guild) ;
		}
		else{
			pick_any_token_in_market(current_player,players, market,guild);
			}
	}

}