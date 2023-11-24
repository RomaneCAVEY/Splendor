#include "game.h"
#include "second_token.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct guild guild;
struct market market;

/**
Init the guild with random value for builders
*/
void init_guild() {
    guild.nbr_builder = num_builders();
    for (int i = 0; i < guild.nbr_builder; ++i) {
        int place= guild.builder_in_guild[builder_level(make_builder(i))].nbr_stack;
        guild.builder_in_guild[builder_level(make_builder(i))-1].stack[place]=make_builder(i);  
    }
}

void init_market() {
    market.nbr_token = NUM_TOKENS;
    for (unsigned int i = 0; i < NUM_TOKENS; ++i) {

        market.available_tokens[i] = make_token(i);
    }
}



/**
Return 1 if the builder is available in the guile, else 0
*/
int is_guild_builder_in_guild(int i) {
    if (guild.builder_in_guild[i]) {
        return 1;
    }
    return 0;

}

/**
Remove token
*/
void remove_token(struct player players[NB_PLAYERS] , struct token_t *token, int current_player) {
    int i=0;
    while(token_equals(*players[current_player].player_token[i], *token)){
        i++;
    }
    players[current_player].player_token[i] = NULL;
}

/*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct player player, struct builder_t * b) {
    if(b){

        struct buildcost_t cost = builder_requires(b);
        unsigned int count_desired_color = 0;
        unsigned int count_just_desired_color = 0;

        //tmp variable used in the loop
        struct token_t * token ;
        struct buildcost_t buildcost;


        // Try to pay with the builders of the player
        for (int i = 0; i <MAX_BUILDERS; ++i){
            
            if(player.player_builder[i]){
                buildcost=builder_provides(player.player_builder[i]);
                if (buildcost.c== cost.c){
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

int guild_nbr_builder() {
    return guild.nbr_builder;
}

int market_nbr_token() {
    return market.nbr_token;
}

void remove_builders_from_guild(struct builder_t * builder) {
    unsigned int i = 0;
    int level=builder_level(builder); 
    while (!builder_t_equals(guild.builder_in_guild[level-1].stack[i], builder) && i<MAX_BUILDERS) {
        i++;
    }
    guild.builder_in_guild[level-1].stack[i] = NULL;
    guild.nbr_builder -=1;
    guild.builder_in_guild[level-1].nbr_stack-=1;
}


struct builder_t * guild_builder_in_guild(unsigned index, int level) {
    return guild.builder_in_guild[level].stack[index];
}

void remove_token_from_market(struct token_t * token){
    for (int i=0; i<NUM_TOKENS; i++){
        if (token== market.available_tokens[i]){
            market.available_tokens[i] = NULL;
            market.nbr_token-=1;
        }
    }
}

void add_token_to_market(struct token_t * token) {
    int i = 0;
     while (market.available_tokens[i] && i< NUM_TOKENS) {
        i++;
    }
    market.available_tokens[i] = token;
    market.nbr_token = market.nbr_token + 1;

}

/* Display the market
*/
void market_display() {
    unsigned int i = 0;
    for (i=0; i< NUM_TOKENS; i++){
        if ( market.available_tokens[i])
        {
            token_display( *market.available_tokens[i], " \n voici le token suivant");
        }
    }
}

/* Return the adress of the token in the market at the place i
*/
struct token_t * token_in_market_is_available(int i) {
    return market.available_tokens[i];
}


/* Pay the builder game_builder[index] with the tokens of the players current_player
*/
void pay(struct player players[NB_PLAYERS], int index, int current){
    //printf(const char *restrict format, ...)
    token_pay(guild_builder_in_guild(index, mak), players, current);
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

                           