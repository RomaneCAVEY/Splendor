#include"power.h"
#include "ansi_color.h"
#include "builder.h"
#include "color.h"
#include "game.h"
#include "guild.h"
#include "player.h"
#include <stdio.h>


const char * power_string[] = {
    "PANIC_MARKET",
    "PANIC_GUILD",
    "TOKEN_STEAL",
    "TURN_STOLEN",
    "MASTER_MAIN",
	"GAIN_FAVOR_WITH_BUILDER",
	"FAVOR_STEAL",
	"MAX"
};

skill skills[NUM_POWER]={
	panic_market,
	guild_panic,
	token_steal,
	steal_turn,
	master_hand,
	gain_favor_with_builder,
	favor_steal
	
};


skill give_the_power(enum power_id power_id){
	return skills[power_id];	
}



const char * power_to_string(enum power_id power_id) {
    if (power_id > 4) {
        return "??????????????";
    }
    return power_string[power_id];
}


/**
The current player chooses the builders he wants to steal
*/
int choose_a_builder(int current_player, struct player players[NB_PLAYERS]){
    int next=(current_player+1)%NB_PLAYERS;
    int index=0;
    unsigned max=builder_points(players[next].player_builder[0]);
    for (int i=1; i<NUM_TOKENS;i++){
        if(builder_points(players[next].player_builder[i]) > max){
            max=builder_points(players[next].player_builder[i]);
            index=i;
        }

    }
    return index;

}

/**
The player pick one of the player of the guild and 
remplace it by one them */


int guild_panic(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
    UNUSED(players);
	UNUSED(current_player);
	UNUSED(ressource);
	UNUSED(market);
	if (guild_nbr_builder(guild)){
		printf(BHRED "\n GUILD_PANIC IS RUNNING!!!!!!! \n" COLOR_RESET);
		printf("The guild before: \n");
		guild_display(guild);
		int random=rand()%MAX_BUILDERS;
		int c=0;
		while(!guild_available_builder((random+c)%MAX_BUILDERS,guild) && (c<(MAX_BUILDERS))	){
			c++;
			//printf("c=%d, \n",c);
		}
		if (c<MAX_BUILDERS){
			struct builder_t* builder= guild_available_builder((random+c)%MAX_BUILDERS,guild);
			//builder_display(builder, "celui qui fait foirer les test");
			//guild_display(guild);
			remove_builders_from_guild(builder,guild);
			//guild_display(guild);
			int level_b= builder_level(builder);
			for (int level = 0; level <NUM_LEVELS; ++level) {
					if(guild->stack[level_b+level].nb){
						guild->builder_available[(random+c)%MAX_BUILDERS]=stack_pop(&guild->stack[level_b+level]);
						return 0;
					}
			}
		// printf("guild.stack[%d].nb = %d !!!!!!!!!!!!!!!!\n",level, guild.stack[level].nb);
		}
		else{
        printf("panic_guild failed, the guild is empty \n");
    }


	}
    
	else{
        printf("panic_guild failed, the guild is empty \n");
    }
	printf("The guild at the end: \n");
	guild_display(guild);
	return 0;

}





/**
Pick an available token market and move it in a random 
empty place of the market
*/
int panic_market(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
    int random= rand();
    int c=0;
	UNUSED(players);
	UNUSED(guild);
	UNUSED(current_player);
	UNUSED(ressource);
	printf(BRED"PANIC_MARKET IS RUNNING!!!!! \n"COLOR_RESET);
    //pick an available random token
	if(market->nbr_token){ 
    while (!make_market((random+c)%NUM_TOKENS,market) && c<NUM_TOKENS){
        c++;
    }
    random=(random+c)%NUM_TOKENS;
    //Find an available place
    if (c!= NUM_TOKENS){
        int i=rand();
        c=0;
        while (make_market((i+c)%NUM_TOKENS,market) && c<NUM_TOKENS){
        c++;
        }
    market_moove_i_to_j((random),(i+c)%NUM_TOKENS,market);
    }
    else{
        printf("panic_market failed");
    }
	}
	return 0;

}

/**
Current player can steal a token to the other player
*/
int token_steal(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
	UNUSED(ressource);
	UNUSED(market);
	UNUSED(guild);
	if (players[current_player].nbr_token< NUM_TOKENS &&  players[current_player+1].nbr_token>0){
        int random= rand();
        int c=0;
        int rank=(random+c)%players[current_player].nbr_token;
        while (!players[(current_player+1)%NB_PLAYERS].player_token[rank] && c<players[current_player].nbr_token){
            ++c;
            rank=(random+c)%players[current_player].nbr_token;
    }
    
        remove_token(players, players[(current_player+1)%NB_PLAYERS].player_token[rank], ((current_player+1)%NB_PLAYERS));
		int nb=players[current_player].nbr_token;
		players[current_player].player_token[nb]=players[(current_player+1)%NB_PLAYERS].player_token[rank];
        }

	printf(BRED"\n TOKEN_STEAL IS RUNNING!!!!!!!!! \n"COLOR_RESET);
    return 0;
    
}



int steal_turn(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
	UNUSED(players);
	UNUSED(market);
	UNUSED(guild);
	UNUSED(ressource);
	if (!current_player){
		return (NB_PLAYERS-1);
	}
	return ((current_player -1));

}



int favor_steal(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
	printf(BRED"\n favor_steal is running \n"COLOR_RESET);
    int random= rand()%NB_PLAYERS;
    int counter=0;
	UNUSED(ressource);
	UNUSED(market);
	UNUSED(guild);
    while((((players[(random+counter)%NB_PLAYERS].favor_nbr<1)) || ((random+counter)%NB_PLAYERS)==current_player) && (((random==current_player) && (counter<NB_PLAYERS)))){
        ++counter;
    }
    if (players[(random+counter)%NB_PLAYERS].favor_nbr>1){
        players[current_player].favor_nbr+=1;
        players[(random+counter)%NB_PLAYERS].favor_nbr-=1;
    }
	return 0;
}

int gain_favor_with_builder(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
    ++players[current_player].favor_nbr;
	UNUSED(ressource);
	UNUSED(market);
	UNUSED(guild);
	return 0;
}

int master_hand(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
    int counter=0;
	printf(BRED"MASTER_HAND IS RUNNING!!!!!!!!! \n"COLOR_RESET);
	struct builder_t *b=ressource;
	UNUSED(guild);
    struct set_t provide=builder_provides(b);
    for(int i=0; i<NUM_TOKENS; ++i){
        counter=0;
        for(int k=0; k<NUM_COLORS; ++k){
            if (token_in_market_is_available(i,market)!=NULL){
                if(provide.ressource[k]>=token_in_market_is_available(i,market)->s.ressource[k]){
					++counter;
				}
                
            }
        }
        if (counter==NUM_COLORS){
            pick_tokens(current_player, players, i,market,guild);
            return 1;
        }
    }
    return 0;

}

