#include "builder.h"

#include "token.h"

#include "color.h"

#include "player.h"

#include "game.h"

#include "second_token.h"

#include "second_builder.h"

#include <stdio.h>

#include <stdlib.h>

#include <threads.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

#define NB_PLAYERS 2


struct player players[NB_PLAYERS];

int main(int argc, char *argv[]){
           int max_turn;
           int seed;
           int seed_builder;
           int opt;

//Mistake in this part: 
           max_turn = 0;
           seed = 0;
           seed_builder = 0;
           while ((opt= getopt(argc, argv, "s:m:c:"))!=(-1)) {
               switch (opt) {
               case 's':
                   seed= atoi(optarg);
                   break;
               case 'm':
                   max_turn = atoi(optarg);
                   break;
                case 'c':
                   seed_builder = atoi(optarg);
                   break;
                   
               default: /* '?' */
                   fprintf(stderr, "Usage: %s [-s seed] [-m max_turn]  [-c seed_builder] \n",
                           argv[0]);
                   exit(EXIT_FAILURE);
               }
           }

           printf("max_turn=%d; seed=%d; seed_builder=%d \n",
                  max_turn, seed, seed_builder );

           if (optind < argc) {
               fprintf(stderr, "Expected argument after options \n");
               exit(EXIT_FAILURE);
           }

    srand(seed);

    //Init player
    for (int i = 0; i < NB_PLAYERS; i++) {
        players[i] = init_player();
        players[i].index = i;
    }
    int current_player = (get_random_player(NB_PLAYERS));
    
    //Init market and guild    
    init_all_tokens(); //comment initialiser les tokens
    init_builders(seed_builder); // Use seed 0 at the beginning of a game   // Same thing
    init_guild(); // il faut initialiser les guild;
    init_market();
    int nb_turns_not_played = 0;
    int nb_turns = 0;

    while (!(has_won(players) && (nb_turns_not_played < 2)) && nb_turns < max_turn) {
        printf("This is the turn %d \n", nb_turns);
        printf("this is the points %d of the current player, player %d\n", players[current_player].points,current_player);
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
            printf("this is the points %d of player %d\n", players[current_player].points,current_player);
             }
             
        //Else we pick some tokens if it's possible;
        else {
                //nb = number between 1 and 3 of tokens the player will pick from the market
                int nb = rand() % 3 +1;
                ///add = number of tokens we have already picked from the market amoung the nb tokens
                int add=0;
                if (nb <= market_nbr_token()){
                    while (add < nb) {
                        
                        //printf("result: %d", nb>add);
                        int random = rand() % NUM_TOKENS;
                       // printf("%d est aléatoire \n", nb);
                        printf("there are %d tokens in the market \n",market_nbr_token());
                        if (token_in_market_is_available(random)) {
                            pick_a_token(current_player, players,random);
                            add+=1;
                        }
                    }
                    printf("Player display of player %d", current_player);
                    player_display(players[current_player]);
                    printf("\n");
                }
                else {
                nb_turns_not_played = nb_turns_not_played + 1;
                 }
        }
        current_player=next_player(NB_PLAYERS, current_player);
        nb_turns += 1;
        player_display(players[current_player]);
    }
    if (players[0].points >= VICTORY_POINTS) {
        printf("Victoire du joueur 0 avec %d points", players[0].points);
        return 0;
    }
    if (nb_turns_not_played >= 2 || (nb_turns==max_turn && players[0].points==players[1].points )) {
        printf("both loose");
        return 0;
    }
    
    printf("Victoire du joueur 1 avec %d points", players[1].points);
    return 0;
}