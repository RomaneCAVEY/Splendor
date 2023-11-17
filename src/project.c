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
    struct player * current_player = get_random_player(NB_PLAYERS, players);
    //Init market and guild    
    init_all_tokens(); //comment initialiser les tokens
    init_tokens_from_builers();
    init_builders(0); // Use seed 0 at the beginning of a game   // Same thing
    init_guild(); // il faut initialiser les guild;
    init_market();
    int nb_turns_not_played = 0;
    int nb_turns = 0;
  

    int possibility = 0;

    while ((!(has_won(players[0], players[1])) && (nb_turns_not_played < 2)) && nb_turns < MAX_TURN) {
        int index;
        for (int i = 0; i < guild_nbr_builder(); i++) {
         //printf("n \n This the market at turn %d \n", nb_turns);
            if (is_guild_builder_in_guild(i)) {
                if (possibility_token_pay( * current_player, make_builder(i))) {
                    possibility = 1;
                    index = i;

                }
            }
        }
        //If we can build a builder then we do it
        if (possibility) {
            //penser à implementer le fait que les tokens utilisés doivent être remis sur le marché
            current_player -> player_token[index + NUM_TOKENS] = adress_token_from_builders(index);

            // put in the market the tokens which were useful to pay the builder, except if they are builders
            token_pay(guild_builder_in_guild(index), current_player);
            add_from_guild(index, current_player);
            remove_builders_from_guild(guild_builder_in_guild(index));

            //Add the ressource linked to the builder that we have added
            current_player -> nbr_builder += 1;
            current_player -> points = builder_points(current_player -> player_builder[current_player -> nbr_builder]) + current_player -> points;
        }
        //Else we take some tokens if it's possible;
        else {
            printf("%d \n", NUM_TOKENS - current_player -> nbr_token);
            if (NUM_TOKENS - current_player -> nbr_token +1) {
                int nb = (NUM_TOKENS - current_player -> nbr_token) % 4;
                if (nb < market_nbr_token()){
                    int add = 0;
                    while (add < nb) {
                        int a = rand() % NUM_TOKENS;
                        printf("%d \n", a);
                        if (token_in_market_is_available(a)) {
                            current_player -> player_token[current_player -> nbr_token] = token_get_adress(a);
                            current_player -> nbr_token = current_player -> nbr_token + 1;
                            remove_token_from_market(token_in_market_is_available(a));
                            add = add + 1;
                        }
                    }
                    player_display(*current_player);
                    printf("\n");
                }
            } 
            else {
                nb_turns_not_played = nb_turns_not_played + 1;
            }
        }
        player_display(*current_player);
        next_player(NB_PLAYERS, players, current_player);
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