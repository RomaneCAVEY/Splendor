#include "builder.h"

#include "color.h"

#include "game.h"
#include "token.h"

#include "player.h"

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include "second_builder.h"

struct builder_t{
    char level;
    int points;
    struct buildcost_t ressource;
    struct buildcost_t production;

};

struct builder_t game_builders[MAX_BUILDERS];
unsigned int nb_builders;

/** Initializes the builders depending on an integer `seed`.
Can be called multiple times. Can also do nothing. */
void init_builders(unsigned int seed) {
    srand(seed);
    nb_builders = 1 + (rand() % (MAX_BUILDERS - 1));
    for (unsigned int i = 0; i < nb_builders; ++i) {
        game_builders[i].level = rand() % NUM_LEVELS;
        game_builders[i].points = rand() % (VICTORY_POINTS);
        game_builders[i].ressource.c = rand() % MAX_COLORS;
        game_builders[i].ressource.n = rand() % 2 + 1;
        game_builders[i].production.c = rand() % MAX_COLORS;
        game_builders[i].production.n = rand() % 2 + 2;
    }
}

/** Returns the total number of builders in the game. */
unsigned int num_builders() {
    return nb_builders;
}

/** Returns the `index`-th builder and NULL if it does not exist. */
struct builder_t * make_builder(unsigned int index) {
    if (index < nb_builders) {
        return & game_builders[index];
    }
    return NULL;
}

/** Returns the level of the builder. */
unsigned int builder_level(const struct builder_t * g) {
    return g -> level;
}

/** Returns the number of points of the builder. */
unsigned int builder_points(const struct builder_t * g) {
    return g -> points;
}

/** Returns the cost that must be payed in order to hire this builder. */
struct buildcost_t builder_requires(const struct builder_t * g) {
    return g -> ressource;
}

/** Returns the cost of the tokens that can be produced by this builder. */
struct buildcost_t builder_provides(const struct builder_t * g) {
    return g -> production;
}

// Option: ADD THE NUMBER OF POINTS THAT WE CAN GET WITH THIS BUILDER
int builder_t_equals(struct builder_t * builder1, struct builder_t * builder2) {
    if (builder1==builder2){
        return 1;
    }
    return 0;
}

/** Displays the builder on the stdout, after a possible prefix.
    Example : builder_display(g, "    - ") displays on the screen :
    - Builder(lvl=1,cost=1W,prod=1B)
*/

void builder_display(const struct builder_t * g, const char * prefix) {
    if (g) {
        printf("%s Builder(lvl= %d, cost=%d %s, prod= %d %s, points = %d) \n \n", prefix, g -> level, g -> ressource.n, color_to_short_string(g -> ressource.c), g -> production.n, color_to_short_string(g -> production.c), g->points);
    } else {
        printf("NULL");
    }
}

/** Add the builder bought in the guild to the player_builder
 */
void add_from_guild(int index, struct player players[NB_PLAYERS] , int current_player) {
    players[current_player].player_builder[players[current_player].nbr_builder] = &game_builders[index];
    players[current_player].points += builder_points(make_builder(index));
    players[current_player].nbr_builder += 1;
}