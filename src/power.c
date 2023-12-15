#include"power.h"
#include "game.h"

const char * power_string[] = {
    "PANIC_MARKET",
    "PANIC_GUILD",
    "TOKEN_STEAL",
    "TURN_STOLEN",
    "MASTER_MAIN",
	"MAX"
};



skill give_the_power(int index){
	return skills[index];	
}

const char * power_to_string(enum power power) {
    if (power > 4) {
        return "??????????????";
    }
    return power_string[power];
}


/**
The current player chooses the builders he wants to steal
*/
int choose_a_builder(int current_player, struct player players[NB_PLAYERS]){
    int next=(current_player+1)%NB_PLAYERS;
    int index=0;
    int max=builder_points(players[next].player_builder[0]);
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
    if (guild_nbr_builder(guild)){
		int random=rand()%MAX_BUILDERS;
		int c=0;
		while(!guild_available_builder((random+c)%MAX_BUILDERS_AVAILABLE_PER_LVL,guild) && (c<(MAX_BUILDERS_AVAILABLE_PER_LVL*NUM_LEVELS))){
			c++;
		}
		remove_builders_from_guild(guild_available_builder(random+c,guild),guild);

	}
    else{
        printf("panic_guild failed, the guild is empty \n");
    }
	return 0;

}





/**
Pick an available token market and move it in a random 
empty place of the market
*/
int panic_market(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
    int random= rand();
    int c=0;
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
    return 0;
    
}



int steal_turn(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
	return ((current_player -1) % NB_PLAYERS);

}



void favor_steal(struct player players[NB_PLAYERS], int current_player) {
    int random= rand()%NB_PLAYERS;
    int counter=0;
    while((players[NB_PLAYERS].favor_nbr=0) || (random==current_player) && (counter<NB_PLAYERS)){
        random=rand()%NB_PLAYERS;
        ++counter;
    }
    if (counter!=NB_PLAYERS){
        ++players[current_player].favor_nbr;
        --players[random].favor_nbr;
    }
}

void gain_favor_with_builder(struct player players[NB_PLAYERS], int current_player) {
    ++players[current_player].favor_nbr;
}

int master_hand(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild){
    int counter=0;
	struct builder_t *b=ressource;
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

skill skills[5]={
	panic_market,
	guild_panic,
	token_steal,
	steal_turn,
	master_hand
};
