#include "builder.h"
#include "token.h"
#include "color.h"
#include "manipulation.h"
#include "player.h"
#include "game.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#define SEED 0
#define MAX_TURN 40
#define VICTORY_POINTS 40
#define EXIT_FAILURE 7
#define NB_MIN_PARAM 3



//struct builder_t* game_builders[MAX_BUILDERS];



int main(int argc, char* argv[]){   
    srand(SEED);
    if (argc < NB_MIN_PARAM){
        printf("there is a mistake");
        return EXIT_FAILURE;
    }

    //Init player
    struct player* current_player = get_random_player();


    //Init market and guild    
    init_builders(0);   // Use seed 0 at the beginning of a game
    init_tokens(0);     // Same thing
    init_guild(); // il faut initialiser les guild;
    init_market();
    int nb_turns_not_played=0;
    int nb_turns=0;
    init_all_tokens(); //comment initialiser les tokens
    init_tokens_from_builers();

    

    int possibility=0;

    while ((!has_won(player1, player2) && nb_turns_not_played<2)&& nb_turns< MAX_TURN){
        int index;
        for (int i=0; i<guild.nbr_builder; i++){
            if(guild.builder_in_guild[i]){
                if (possibility_token_pay(current_player->player_token, game_builders[i])){
                    possibility=1;
                    index=i;

        }
        }
    }
    if (possibility){
        //penser à implementer le fait que les tokens utilisés doivent être remis sur le marché
        current_player->player_token[index+ NUM_TOKENS-1]= &tokens_from_builders[index];

        // put in the market the tokens which were useful to pay the builder, except if they are builders
        token_pay(current_player->player_token, *guild.builder_in_guild[index], market);
        current_player->player_builder[current_player->nbr_builder]= guild.builder_in_guild[index];
        remove_builders_from_guild(guild, *guild.builder_in_guild[index]);

        //Add the ressource linked to the builder that we have added
        current_player->nbr_builder +=1;
        current_player->points= builder_points(current_player->player_builder[current_player->nbr_builder]) +current_player->points;
    }
    else{
        if(NUM_TOKENS - current_player->nbr_token){
            int nb=(NUM_TOKENS-current_player->nbr_token) % 3;
            int add=0;
            while (add<nb){
                int a =srand() % market.nbr_token;    if(NUM_TOKENS - current_player->nbr_token){
            int nb=(NUM_TOKENS-current_player->nbr_token) % 3;
            int add=0;
            while (add<nb){
                int a =srand() % market.nbr_token;
                if (market.available_tokens[a]){
                    current_player->player_token[current_player->nbr_token]=&all_tockens[a];
                    current_player->nbr_token= current_player->nbr_token +1;
                    market.available_tokens[a]=0;
                    add=add+1;
                }
            }
        }
        else {
                nb_turns_not_played= nb_turns_not_played+1;
            }
                if (market.available_tokens[a]){
                    current_player->player_token[current_player->nbr_token]=&all_tockens[a];
                    current_player->nbr_token= current_player->nbr_token +1;
                    market.available_tokens[a]=0;
                    add=add+1;
                }
            }
        }
        else {
                nb_turns_not_played= nb_turns_not_played+1;
            }
        }
    next_player(current_player);
}
    if(player1.points >= VICTORY_POINTS){
        printf("Victoire du joueur 1 avec %d points", player1.points);
    }
    if(nb_turns_not_played >= 2){
        printf("both loose");
    }
    else {
         printf("Victoire du joueur 2 avec %d points", player2.points);
    }
    return 0;
}