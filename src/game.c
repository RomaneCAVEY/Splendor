#include "game.h"

#include "player.h"

#include "builder.h"

#include "second_token.h"

#include "token.h"

#include <stdio.h>
#include <stdlib.h>

struct guild guild;
struct market market;
struct token_t tokens_from_builders[MAX_BUILDERS];

/**
Init the guild with random value for builders
*/
void init_guild() {
    guild.nbr_builder = num_builders();
    for (int i = 0; i < guild.nbr_builder; ++i) {

        guild.builder_in_guild[i] = make_builder(i);
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
Transform the ressources of builder in token 
*/
void init_tokens_from_builers() {
    for (int i = 0; i < guild.nbr_builder; ++i) {
        /*
            for each builder build, we add the tokens that we can ues to pay another builders
        */
        struct token_t tmp = create_simple_token(builder_requires(make_builder(i)).c);
        tmp.c[builder_requires(make_builder(i)).c] = (builder_requires(make_builder(i)).n);
        tokens_from_builders[i+NUM_TOKENS]=tmp;
    }
}

/**
Return the adress of the token created by a builder
*/
struct token_t * adress_token_from_builders(int i) {
    return & tokens_from_builders[i];
}

/**
Remove 
*/
void remove_token(struct player* player , struct token_t *token) {
    for (int i = 0; i < NUM_TOKENS; ++i)
    {
        if(player->player_token[i] == token)
        {
            player->player_token[i] = NULL;
        }

    }
}

/*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct player player, struct builder_t * b) {
    if(b){
        struct buildcost_t cost = builder_requires(b);
        unsigned int count_desired_color = 0;
        unsigned int count_just_desired_color = 0;
        for (int i = 0; i < NUM_TOKENS + MAX_BUILDERS; ++i){
            struct token_t * t = player.player_token[i];
            if (t){
                count_desired_color = count_desired_color + t -> c[cost.c];
                if (is_complex(t[i])) {
                    if (t -> c[cost.c] == 2) {
                        count_just_desired_color = count_desired_color + 2;
                    }
                }
                else{
                    count_just_desired_color = count_desired_color + t -> c[cost.c];
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
void token_pay(struct builder_t * b, struct player * player) {
    if (b){
    struct buildcost_t cost = builder_requires(b);
    int count = 0;
    int i = 0;
    while (i < (NUM_TOKENS + MAX_BUILDERS)) {
        if(player -> player_token[i]){
            if (player -> player_token[i] -> c[cost.c]) {
                add_token_to_market(player -> player_token[i]);
                count = count + player -> player_token[i] -> c[cost.c];
                if (i < NUM_TOKENS) {
                    remove_token(player, player->player_token[i]);
                }
            }
        }
        if (count == cost.n){
            i=NUM_TOKENS + MAX_BUILDERS; 
        }
        i++;
        }
    }
}

int guild_nbr_builder() {
    return guild.nbr_builder;
}

int market_nbr_token() {
    return market.nbr_token;
}

void remove_builders_from_guild(struct builder_t * builder) {
    unsigned int i = 0;
    while (!builder_t_equals(make_builder(i), builder)) {
        i++;
    }
    guild.builder_in_guild[i] = NULL;
}

struct builder_t * guild_builder_in_guild(int index) {
    return guild.builder_in_guild[index];
}

void remove_token_from_market(struct token_t * token){
    for (int i=0; i<NUM_TOKENS; i++){
        if (token== market.available_tokens[i]){
            market.available_tokens[i] = NULL;
        }
    }
}

void add_token_to_market(struct token_t * token) {
    int i = 0;
    while (market.available_tokens[i]) {
        i++;
    }
    market.available_tokens[i] = token;
    market.nbr_token = market.nbr_token + 1;

}


void market_display() {
    unsigned int i = 0;
    for (i=0; i< NUM_TOKENS; i++){
        if ( market.available_tokens[i])
        {
            token_display( *market.available_tokens[i], " \n voici le token suivant");
        }
    }
}


struct token_t * token_in_market_is_available(int i) {
    return market.available_tokens[i];
}

