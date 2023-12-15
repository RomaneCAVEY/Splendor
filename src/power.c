#include"power.h"
#include "builder.h"


const char * power_string[] = {
    "PANIC_MARKET",
    "PANIC_GUILD",
    "TOKEN_STEAL",
    "TURN_STOLEN",
    "MASTER_MAIN",
	"MAX"
};




//eum de poitneur de fonction
const char * power_to_string(enum power power) {
    if (power > 4) {
        return "??????????????";
    }
    return power_string[power];
}


#include"guild.h"
#include"market.h"


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


int guild_panic(int current_player, struct player players[NB_PLAYERS], void* ressource){
   
    if (guild_nbr_builder()){
		int random=rand()%MAX_BUILDERS;
		int c=0;
		while(!guild_available_builder((random+c)%MAX_BUILDERS_AVAILABLE_PER_LVL) && (c<(MAX_BUILDERS_AVAILABLE_PER_LVL*NUM_LEVELS))){
			c++;
		}
		remove_builders_from_guild(guild_available_builder(random+c));

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
int panic_market(int current_player, struct player players[NB_PLAYERS], void* ressource){
    int random= rand();
    int c=0;
    //pick an available random token 
    while (!make_market((random+c)%NUM_TOKENS) && c<NUM_TOKENS){
        c++;
    }
    random=(random+c)%NUM_TOKENS;
    //Find an available place
    if (c!= NUM_TOKENS){
        int i=rand();
        c=0;
        while (make_market((i+c)%NUM_TOKENS) && c<NUM_TOKENS){
        c++;
        }
    market_replace((random),(i+c)%NUM_TOKENS);
    }
    else{
        printf("panic_market failed");
    }
	return 0;

}

skill give_the_power(int index){
	return skills[index];
}


/**
Current player can steal a token to the other player
*/
int token_steal(int current_player, struct player players[NB_PLAYERS], void* ressource){
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



int steal_turn(int current_player, struct player players[NB_PLAYERS], void* ressource){
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

int master_hand(int current_player, struct player players[NB_PLAYERS], void* ressource){
    int counter=0;
	struct builder_t *b=ressource;
    struct set_t provide=builder_provides(b);
    for(int i=0; i<NUM_TOKENS; ++i){
        counter=0;
        for(int k=0; k<NUM_COLORS; ++k){
            if (market.playing_board[i]!=NULL){
                provide.ressource[k]=market.playing_board[i]->s.ressource[k];
                
            }
        }
        if (counter==NUM_COLORS){
            pick_tokens(current_player, players, i);
            return 1;
        }
    }
    return 0;

}