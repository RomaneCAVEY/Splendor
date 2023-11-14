#include "game.h"
#include "second_token.h"
#include "token.h"

struct guild guild;
struct market market; 
struct token_t tokens_from_builders[MAX_BUILDERS];

/**
Init the guild with random value for builders
*/
void init_guild(){
    guild.nbr_builder= num_builders();
    for (unsigned int i=0; i< guild.nbr_builder;++i){

        guild.builder_in_guild[i]=make_builder(i);
    }
}


void init_market(){
    market.nbr_token=NUM_TOKENS;
    for (unsigned int i=0; i< NUM_TOKENS;++i){

        market.available_tokens[i]=make_token(i);
}
}


/**
Return 1 if the builder is available in the guile, else 0
*/
int is_guild_builder_in_guild(int i){
    if (guild.builder_in_guild[i]){
        return 1;
    }
    return 0;


}

/**
Transform the ressources of builder in token 
*/
void init_tokens_from_builers(){
    for (int i=0; i< guild.nbr_builder; ++i){
        /*
            for each builder build, we add the tokens that we can ues to pay another builders
        */
        struct token_t tmp= create_simple_token(builder_requires(make_builder(i)).c);
        tmp.c[builder_requires(make_builder(i)).c]=(builder_requires(make_builder(i)).n);
    }
}



/**
Return the adress of the token created by a builder
*/
struct token_t* adress_token_from_builders(int i){
    return &tokens_from_builders[i];
}

/**
Remove 
*/
void remove_token(struct token_t* tab[], const struct token_t token){
    int i=0;
    while(token_equals(token,*tab[i])){
        i++;
    }
     tab[i]=NULL;
}



//Pay the builder with the tokens of the player, remove the token used to pay and put the token ont the market
void token_pay(struct builder_t *b,struct player* player)
{
    struct buildcost_t cost= builder_requires(b);
    int count=0;
    int i=0;
    while (i < (NUM_TOKENS+MAX_BUILDERS)){
        if(player->player_token[i]->c[cost.c]){
            market.available_tokens[market.nbr_token]=NULL;
            market.nbr_token= market.nbr_token +1;
            count= count+ player->player_token[i]->c[cost.c]; 
            if (i< NUM_TOKENS){
                remove_token( player->player_token,*player->player_token[i]);
            }
        
        }
    }
}

int guild_nbr_builder(){
    return guild.nbr_builder;
}

int market_nbr_token(){
    return market.nbr_token;
}



void remove_builders_from_guild(struct builder_t* builder){
    unsigned int i=0;
    while(!builder_t_equals(make_builder(i), builder)){
        i++;
    }
    guild.builder_in_guild[i]=NULL;
}


struct builder_t* guild_builder_in_guild(int index){
    return guild.builder_in_guild[index];
}


void remove_token_from_market(struct token_t* token){
    unsigned int i=0;
    while(!token_equals(*make_token(i),*token)){
        i++;
    }
    market.available_tokens[i]=NULL;
}

void add_token_to_market(struct token_t* token){
    unsigned int i=0;
    while(market.available_tokens[i]){
        i++;
    }
    market.available_tokens[i]=token; 

}

struct token_t* token_in_market_is_available(int i){
    return market.available_tokens[i];
}