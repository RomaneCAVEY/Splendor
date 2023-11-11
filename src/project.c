#include "token.h"
#include "color.h"
#include "builder.h"
#include <stdio.h>
#include <time.h>
#define SEED 

struct player{
    struct token_t* player_token[NUM_TOKENS];
    struct builder_t* player_builder[MAX_BUILDERS];
    int points;
    int nbr_token;
    int nbr_builder;

};


void remove_token(struct token_t* tab[], const struct token_t token){
    int i=0;
    while(token_equals(token,*tab[i])){
        i++;
    }
     while(i<(NUM_TOKENS-2)){
        tab[i]=tab[i+1];
        ++i;
    }

}

void token_pay(struct builder_t *b, struct player player)
{
    struct buildcost_t cost= builder_requires(b);
    int count_desired_color=0;
    for (int i=0; i < NUM_TOKENS; ++i){
        if(player.player_token[i].c[cost.c]){
            remove_token(player.player_token, player.player_token[i]);
        }
    }
}

void remove_builders_from_guild(struct guild guild, struct builder_t builder){
    int i=0;
    while(guild.builder_in_guild[i]!= builder){
        i++;
    }
     while(i<(MAX_BUILDERS-2)){
        guild.builder_in_guild[i]=guild.builder_in_guild[i+1];
        ++i;
    }




int has_won(struct player player1, struct player player2){
    if (player1.points> =VICTORY_POINTS || player2.points>= VICTORY_POINTS){
        return 1;
    }
    return 0;
}


struct player get_random_player(){
    int a= srand() % 2;
    if (a){
        return player2;
    }
    return player1;
      
}

void next_player(current_player){
    if (current_player==player1){
        current_player= player2;
    }
    current_player=player1;
}


struct player init_player(){
    struct player player;
    player.points=0;
    player.token={};
    player.tab_builder={};
    return player;
}

int main(int argc, char* argv[]){   
    srand(seed: SEED);
    if (argc < NB_MIN_PARAM){
        printf("there is a mistake");
        return EXIT_FAILURE;
    }

    //init player
    current_player = get_random_player();
    struct player player1= init_player() ;
    struct player player2= init_player();


    //init market and guild    
    struct builder_t* game_builders[MAX_BUILDERS]={NULL};
    struct guild guild;
    guild.nbr_builder=num_builders;
    guild.builder_in_guilde=; // il faut initialiser les bilders;
    struct market market;
    market.nbr_token=MAX_TOKEN;
    market.token_in_market={0}; // Initialiser à 0, car tous les jetons appartiennet à la pioche au début du jeu
    init_builders(0);   // Use seed 0 at the beginning of a game
    init_tokens(0);     // Same thing
    int nb_turns_not_played=0;
    int nb_turns=0;
    struct token_t m[MAX_TOKEN]={}; /comment initialiser les tokens 
    

    int possibility=0;

    while ((has_won(player1, player2) && nb_turns_not_played<2)&& nb_turns< MAX_TURN){
        int index;
        for (int i=0, i<guild.nbr_builder, i++){
            if (token_pay(current_player.tab_token, guild.builder_in_guilde[i])){
                possibility=1;
                index=i;

        }
    }
    if (possibility){

        available_cards = guild.builder_in_guilde;
        struct builder a_builder = guild.builder_in_guild[index];
        current_player.player_builder[current_player.nbr_builder]= a_builder;
        remove_builders_from_guild(guild, a_builder);
        struct token_t tmp= create_simple_token(a_builder.ressource.c);
        tmp[a_builder.ressource.c]=a_builder.ressource.n;
        current_player.player_token[nbr_token]= tmp;
        current_player.tab_token->nbr_token=current_player.tab_token->nbr_token +1;
        current_player->points= builder_provides(current_player.player_builder[current_player.nbr_builder]).n +current_player->points;
        //pas compris comment on transforme ce que ça rapporte en points
    }
    else{
    if(MAX_TOKEN-current_player.nbr_token){
        int nb=(MAX_TOKEN-current_player.nbr_token)% 3;
        int add=0;
        while (add<nb){
            int a =srand() % MAX_TOKEN;
            if (market.available_tokens[a]){
                current_player.player_token[current_player.nbr_token]=m[a];
                current_player->nbr_token= current_player->nbr_token +1;
                market.available_tokens[a]=0;
                add=add+1;
            }}
        }
        else {
             nb_turns_not_played= nb_turns_not_played+1;
        }
        }
    current_player = next_player(current_player);*/
}
    if(player1.points> =VICTORY_POINTS){
        printf("Victoire du joueur 1 avec %d points", player1.points);
    }
    if(nb_turns_not_played>=2){
        printf("both loose");
    }
    else {
         printf("Victoire du joueur 2 avec %d points", player2.points);
    }
    return 0;
}