#include"power.h"
#include"guild.h"
#include"market.h"

const char * power_string[] = {
    "PANIC_MARKET",
    "PANIC_GUILD",
    "TOKEN_STEAL",
    "TURN_STOLEN",
    "MASTER_MAIN",
	"NULL"
};

const char * power_to_string(enum power power) {
    if (power > MAX_COLORS) {
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
The player pick one of the builder of the guild and 
remplace it by one them

void guild_panic(){
   
    if (c!= MAX_BUILDERS){

    }
    else{
        printf("panic_guild failed");
    }

}

*/




/**
Pick an available token market and move it in a random 
empty place of the market
*/
void panic_market(){
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

}

/**
Current player can steal a token to the other player
*/

void token_steal(int current_player, int player_to_steal, struct player players[NB_PLAYERS]){
    if (players[current_player].nbr_token< NUM_TOKENS){
        int random= rand();
        int c=0;
        int rank=(random+c)%players[current_player].nbr_token;
        while (!players[(current_player+1)%NB_PLAYERS].player_token[rank] && c<players[current_player].nbr_token){
            ++c;
            rank=(random+c)%players[current_player].nbr_token;
    }
    
    for (int i=0; i<NUM_TOKENS; i++) {
        if(!players[current_player].player_token[i]){
            players[current_player].player_token[i]=players[(current_player+1)%NB_PLAYERS].player_token[rank];
            break;
        }
    
    }
    remove_token(players, players[(current_player+1)%NB_PLAYERS].player_token[rank], ((current_player+1)%NB_PLAYERS));


    }

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

void gain_favor_with_builder(struct players[NB_PLAYERS], int current_player) {
    ++players[current_player].favor_nbr;
}

int master_hand(struct players[NB_PLAYERS], int current_player, sruct builder_t b) {
    int counter=0;
    struct set provide=builder_provides(b);
    for(int i=0; i<NUM_TOKENS; ++i){
        counter==0;
        for(int k=0; k<NUM_COLORS; ++k){
            if (market.playing_board[i]!=NULL){
                provide[k]<=market.playing_board[i]->s[k];
                
            }
        }
        if (counter==NUM_COLORS){
            pick_tokens(current_player, players, i);
            return 1;
        }
    }
    return 0;

}

