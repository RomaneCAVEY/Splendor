#include "builder.h"

#include "color.h"

#include "token.h"

#include "player.h"

#include <stdio.h>

#include <stdlib.h>

#include <time.h>
<<<<<<< HEAD

struct builder_t {
    char level;
    int points;
    struct buildcost_t ressource;
    struct buildcost_t production;

};
=======
#include "second_builder.h"
>>>>>>> refs/remotes/origin/master

struct builder_t game_builders[MAX_BUILDERS];
unsigned int nb_builders;

/** Initializes the builders depending on an integer `seed`.
Can be called multiple times. Can also do nothing. */
void init_builders(unsigned int seed) {
    srand(seed);
    nb_builders = 1 + (rand() % (MAX_BUILDERS - 1));
    for (int i = 0; i < nb_builders; ++i) {
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

// ADD THE NUMBER OF POINTS THAT WE CAN GET WITH THIS BUILDER
int builder_t_equals(struct builder_t * builder1, struct builder_t * builder2) {
    for (int i = 0; i < MAX_BUILDERS; ++i) {
        if (builder1 -> level != builder2 -> level) {
            return 0;
        }
        if (builder1 -> points != builder2 -> points) {
            return 0;
        }
        if ((builder1 -> ressource.c != builder2 -> ressource.c) || (builder1 -> ressource.n != builder2 -> ressource.n)) {
            return 0;
        }
        if ((builder1 -> production.c != builder2 -> production.c) || (builder1 -> production.n != builder2 -> production.n)) {
            return 0;
        }

    }
    return builder1 -> points;
}

/** Displays the builder on the stdout, after a possible prefix.
    Example : builder_display(g, "    - ") displays on the screen :
    - Builder(lvl=1,cost=1W,prod=1B)
*/
<<<<<<< HEAD
void builder_display(const struct builder_t * g,
    const char * prefix) {
    if (g) {
        printf("This builder has : %d as ressources \n", g -> ressource.c);
        printf("This builder has : %d as production \n", g -> production.c);
        printf("%s Builder(lvl= %d, cost=%d %s, prod= %d %s \n", prefix, g -> level, g -> ressource.n, color_to_short_string(g -> ressource.c), g -> production.n, color_to_short_string(g -> production.c));
    } else {
        printf("NULL");
    }
=======
void builder_display(const struct builder_t* g, const char* prefix){
    printf("%s Builder(lvl= %d, cost=%d %s, prod= %d %s)\n", prefix ,g->level,g->ressource.n,color_to_short_string(g->ressource.c), g->production.n,color_to_short_string(g->production.c) );
>>>>>>> refs/remotes/origin/master
}

/** Add the builder bought in the guild to the player_builder
 */
void add_from_guild(int index, struct player * current_player) {
    current_player -> player_builder[current_player -> nbr_builder] = & game_builders[index];
}