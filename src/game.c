#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/**
Remove token
*/
void remove_token(struct player players[NB_PLAYERS] , struct token_t *token, int current_player) {
    int i=0;
    while(token_equals(*players[current_player].player_token[i], *token) && i<NUM_TOKENS){
        i++;
    }
    if (i<NUM_TOKENS){
        players[current_player].player_token[i] = NULL;
    }
    else{
        printf("the token wasnt' found");
    }
}
    

/*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct player player, struct builder_t * b) {
    if(b){

        struct set_t cost= builder_requires(b);
        unsigned int count_desired_color = 0;
        unsigned int count_just_desired_color = 0;

        //tmp variable used in the loop
        struct token_t * token ;
        struct set_t buildcost;


        // Try to pay with the builders of the player
        for (int i = 0; i <MAX_BUILDERS; ++i){
            
            if(player.player_builder[i]){
                buildcost=builder_provides(player.player_builder[i]);
                if (player.player_builder[]){
                    count_desired_color += cost.c;
                    count_just_desired_color+= cost.c;

                }
            }

        }
        if (count_desired_color>= cost.c){
            return 4;
        }
        // Try to pay the rest with the tokens of the player

         for (int i = 0; i <NUM_TOKENS; ++i){
            token = player.player_token[i];
            if (token){
                count_desired_color = count_desired_color + token-> c[cost.c];
                if (is_complex(token)) {
                    if (token-> c[cost.c] == 2) {
                        count_just_desired_color = count_desired_color + 2;
                    }
                }
                else{
                    count_just_desired_color = count_desired_color + token-> c[cost.c];
                 }
            }
        }
        if (count_just_desired_color >= cost.c) {
            return 1;
        }
        if (count_desired_color > cost.c) {
            return 2;
        }
    }
    return 0;
}



//Pay the builder with the tokens of the player, remove the token used to pay and put the token on the market
int token_pay(struct builder_t * builder, struct player players[NB_PLAYERS], int current_player) {
    if (possibility_token_pay(players[current_player], builder)){
        return 1;
    }
    struct buildcost_t cost = builder_requires(builder);
    unsigned int count = 0;
    struct token_t * token ;
    struct buildcost_t buildcost;


        //Pay with the builders of the player
        for (int i = 0; i <MAX_BUILDERS; ++i){
            if(players[current_player].player_builder[i]){
                buildcost=builder_provides(players[current_player].player_builder[i]);
                if (buildcost.c== cost.c){
                    count += cost.c;
                }
            }

        }
        if (count>= cost.c){
            return 1;
        }
        // Pay the rest with the tokens of the player

         for (int i = 0; i <NUM_TOKENS; ++i){
            token = players[current_player].player_token[i];
            if (token){
                if (token-> c[cost.c]){
                    count+= token->c[cost.c];
                    add_token_to_market(players[current_player].player_token[i]);
                    remove_token(players, players[current_player].player_token[i], current_player);
                }
            }
        
        }
        return 1;

}



/* Pay the builder game_builder[index] with the tokens of the players current_player
*/
void pay(struct player players[NB_PLAYERS], int index, int current){
    //printf(const char *restrict format, ...)
    token_pay(guild_builder_in_guild(index), players, current);
    //printf(" \n payed \n ");
    add_from_guild(index, players, current);
    remove_builders_from_guild(guild_builder_in_guild(index));
}

/* Pick a token in the market, add in the player's token list, and remove it from the market
*/
void pick_a_token(int current_player, struct player players[NB_PLAYERS], int a){
    players[current_player].player_token[players[current_player].nbr_token] = token_get_adress(a);
    //printf("adress of the token %d : %p",current_player, token_get_adress(a));
    players[current_player].nbr_token = players[current_player].nbr_token + 1;
    remove_token_from_market(token_in_market_is_available(a));

}

                           