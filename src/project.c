#include "token.h"
#include "color.h"
#include "builder.h"
#include <stdio.h>
#include <time.h>

struct player{
    struct token_t* player_token[NUM_TOKENS];
    struct builder_t* player_builder[MAX_BUILDERS];
    int points;
    int nbr_token;
    int nbr_builder;

};



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


int main(int argc, char* argv[]){   
struct builder_t* game_builders[MAX_BUILDERS];
struct guild guild;
guild.nbr_builder=num_builders;
guild.builder_in_guilde=; // il faut initialiser les bilders;
struct market market;
market.nbr_token=MAX_TOKEN;
market.token_in_market={0}; 

init_builders(0);   // Use seed 0 at the beginning of a game
init_tokens(0);     // Same thing
int nb_turns_not_played=0;
int nb_turns=0;
struct token_t m[MAX_TOKEN]={}; /comment initialiser les tokens 
current_player = get_random_player();
struct player player1;
player1.points=0;
player1.token={};
player1.tab_builder={};
struct player player2;
player2.points=0;
player2.token={};
player2.tab_builder={};

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
    else:
        int nb=(MAX_TOKEN-current_player.nbr_token)% 3;
        int add=0;
        while (add<nb){
            int a =srand() % MAX_TOKEN;
            if (market.available_tokens[a]){
                current_player.player_token[current_player.nbr_token]=m[a];
                current_player->nbr_token= current_player->nbr_token +1;
                market.available_tokens[a]=0;
                add=add+1;
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