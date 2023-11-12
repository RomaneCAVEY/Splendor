#include "builder.h"
#include "token.h"
#include "color.h"
#include "manipulation.h"
#include "player.h"
#include "game.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

struct guild guild;
struct market market; 
struct token_t tokens_from_builders[MAX_BUILDERS];

struct guild init_guild(){
    struct guild guild;
    guild.nbr_builder= num_builders();
    struct builder_t* builder_in_guild[MAX_BUILDERS];
    for (int i=0; i< guild.nbr_builder;++i){

        guild.builder_in_guild[i]=make_builder(i);
    }
}
struct market init_market(){
    struct market market;
    market.nbr_token=NUM_TOKENS;
    memset(market.available_tokens, 0, NUM_TOKENS); /*Initialiser à 0, 
    car tous les jetons appartiennet à la pioche au début du jeu*/
}


void init_tokens_from_builers(){
    for (int i=0; i< guild.nbr_builder; ++i){
        struct token_t tmp= create_simple_token(*(guild.builder_in_guild[i]).ressource.c);
        tmp[guild.builder_in_guild[i]->ressource.c]=guild.builder_in_guild[i]->ressource.n;
        tokens_from_builders[i]=tmp;
    }
    

}

//Pay the builder with the tokens of the player
void token_pay(struct builder_t *b, struct player player, struct market market)
{
    struct buildcost_t cost= builder_requires(b);
    int count=0;
    int i=0;
    while (i < (NUM_TOKENS+MAX_BUILDERS)){
        if(player.player_token[i]->c[cost.c]){
            market.available_tokens[market.nbr_token]=0;
            market.nbr_token= market.nbr_token +1;
            count= count+ player.player_token[i]->c[cost.c]; 
            if (i< NUM_TOKENS){
                remove_token( player.player_token,*player.player_token[i]);
            }

        }
    }
}

void remove_builders_from_guild(struct guild guild, struct buildcost_t builder){
    int i=0;
    while(!builder_t_equals(*guild.builder_in_guild[i], builder)){
        i++;
    }
    guild.builder_in_guild[i]=NULL;
}
     