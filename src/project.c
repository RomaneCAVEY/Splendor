#include "builder.h"

#include "token.h"

#include "color.h"

#include "manipulation.h"

#include "player.h"

#include "game.h"

#include "second_token.h"

#include "second_builder.h"

#include <stdio.h>

#include <stdlib.h>

#include <threads.h>
#include <time.h>

#include <string.h>

#define SEED 0
#define MAX_TURN 40
#define NB_MIN_PARAM 1
#define NB_PLAYERS 2

struct player players[NB_PLAYERS];

int main(int argc, char * argv[]) {
    srand(SEED);
    if (argc < NB_MIN_PARAM) {
        printf("there is a mistake, too few arguments");
        return EXIT_FAILURE;
    }

    //Init player

    for (int i = 0; i < NB_PLAYERS; i++) {
        players[i] = init_player();
        players[i].index = i;
    }
    int current_player = (get_random_player(NB_PLAYERS));
    //Init market and guild    
    init_all_tokens(); //comment initialiser les tokens
    init_tokens_from_builers();
    init_builders(0); // Use seed 0 at the beginning of a game   // Same thing
    init_guild(); // il faut initialiser les guild;
    init_market();
    int nb_turns_not_played = 0;
    int nb_turns = 0;

    while (!(has_won(players) && (nb_turns_not_played < 2)) && nb_turns < MAX_TURN) {
        int index;
        int possibility_to_pay=0;
        for (int i = 0; i < guild_nbr_builder(); i++) {
         //printf("n \n This the market at turn %d \n", nb_turns);
            if (is_guild_builder_in_guild(i)) {
                if (possibility_token_pay(players[current_player], make_builder(i))) {
                    possibility_to_pay = possibility_token_pay(players[current_player], make_builder(i));
                    index = i;

                }
            }
        }
        printf("===============================: \n");
        printf("Market display: \n");
        market_display();
        printf("===============================: \n");
        printf("this is the possibility %d\n", possibility_to_pay);

        //If we can build a builder then we do it
        if (possibility_to_pay) {
            //put in the market the tokens which were useful to pay the builder, except if they are builders
            pay(players,index, current_player);
            printf("%d\n", players[current_player].points);
             }
             
        //Else we pick some tokens if it's possible;
        else {
                int nb = rand() % 4;
                int add=0;
                if (nb < market_nbr_token()){
                    //printf(" Voici %d \n", nb-add);
                    while (add < nb) {
                        int random = rand() % NUM_TOKENS;
                        //printf("%d est aléatoire \n", a);
                        if (token_in_market_is_available(random)) {
                            pick_a_token(current_player, players,random);
                            add+=1;
                        }
                    }
                    player_display(players[current_player]);
                    printf("\n");
                }
                else {
                nb_turns_not_played = nb_turns_not_played + 1;
                 }
        }
        current_player=next_player(NB_PLAYERS, current_player);
        nb_turns += 1;
    }
    if (players[0].points >= VICTORY_POINTS) {
        printf("Victoire du joueur 1 avec %d points", players[0].points);
    }
    if (nb_turns_not_played >= 2) {
        printf("both loose");
    } else {
        printf("Victoire du joueur 2 avec %d points", players[1].points);
    }
    return 0;
}