#include "game.h"

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


int is_market_available_tokens(int a ){
    return market.available_tokens[a];
}

void change_market_available_tokens(int a,int b){
    market.available_tokens[a]=b;
}

int is_guild_builder_in_guild(int i){
    if (guild.builder_in_guild[i]){
        return 1;
    }
    return 0;


}

void init_tokens_from_builers(){
    for (int i=0; i< guild.nbr_builder; ++i){
        /*
            for each builder build, we add the tokens that we can ues to pay another builders
        */
        struct token_t tmp= create_simple_token(builder_requires(make_builder(i)).c);
        tmp.c[builder_requires(make_builder(i)).c]=(builder_requires(make_builder(i)).n);
    }
}




struct token_t* adress_token_from_builders(int i){
    return &tokens_from_builders[i];
}


void remove_token(struct token_t* tab[], const struct token_t token){
    int i=0;
    while(token_equals(token,*tab[i])){
        i++;
    }
     tab[i]=NULL;
}


//Pay the builder with the tokens of the player
void token_pay(struct builder_t *b,struct player* player)
{
    struct buildcost_t cost= builder_requires(b);
    int count=0;
    int i=0;
    while (i < (NUM_TOKENS+MAX_BUILDERS)){
        if(player->player_token[i]->c[cost.c]){
            market.available_tokens[market.nbr_token]=0;
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

void add_in_guild(int index, struct player* current_player){
    current_player->player_builder[current_player->nbr_builder]= guild.builder_in_guild[index];
}