#include "builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef VICTORY_POINTS
#define VICTORY_POINTS 20
#define MIN_BUILDER 5
struct builder_t{
    char level;
    int points;
    struct set_t ressource;
    struct set_t production;

};

struct builder_t game_builders[MAX_BUILDERS]={};
unsigned int nb_builders;

/** Initializes the builders depending on an integer `seed`.
Can be called multiple times. Can also do nothing. */
void init_builders(unsigned int seed) {
    srand(seed);
    nb_builders =(rand() % (MAX_BUILDERS-MIN_BUILDER)+MIN_BUILDER);
    printf("HERE IS THE NUMBER OF BUILDERS: %d \n",nb_builders);
    for (unsigned int i = 0; i < nb_builders; ++i) {
        game_builders[i].level = rand() % NUM_LEVELS;
        game_builders[i].points = rand() % (VICTORY_POINTS/2);
        game_builders[i].ressource.ressource[rand() % NUM_COLORS]+=1;
        game_builders[i].ressource.ressource[rand() % NUM_COLORS]+=1;
        game_builders[i].production.ressource[rand() % NUM_COLORS]+=1;
        game_builders[i].production.ressource[rand() % NUM_COLORS]+=1;
		builder_display(&game_builders[i], "This is a new builder");
    }
}

/** Returns the total number of builders in the game. */
unsigned int num_builders() {
    //printf("num_builders: %d \n",nb_builders );
	if (nb_builders<=MAX_BUILDERS){
   		return nb_builders;
	}
	else{
		return MAX_BUILDERS;
	}
}



/** Returns the `index`-th builder and NULL if it does not exist. */
struct builder_t *make_builder(unsigned int index) {
    if (index <MAX_BUILDERS) {
        return &game_builders[index];
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
struct set_t builder_requires(const struct builder_t * g) {
    return g -> ressource;
}

/** Returns the cost of the tokens that can be produced by this builder. */
struct set_t builder_provides(const struct builder_t* g){
    return g -> production;
}



/** Displays the builder on the stdout, after a possible prefix.
    Example : builder_display(g, "    - ") displays on the screen :
    - Builder(lvl=1,cost=1W,prod=1B)
*/

void builder_display(const struct builder_t * builder, const char * prefix) {
    //printf("%p \n", &g);
    if (builder) {
        printf("%s Builder(lvl= %d, cost= ( ",prefix, builder-> level);
        for (unsigned int i=0; i<NUM_COLORS; ++i){
            if (builder -> ressource.ressource[i]>0){
                printf("(%s=%d),",color_to_short_string(i),  builder-> ressource.ressource[i]);

            }

        }
        printf(")    ");
        printf(", prod: {");
         for (unsigned int i=0; i<NUM_COLORS; ++i){
            if (builder-> production.ressource[i]>0){
                 printf("(%s=%d),",color_to_short_string(i),  builder -> production.ressource[i]);
            }

        }
        printf("}  ");
        printf(" ,points = %d) \n \n", builder->points);
    }
}

#endif