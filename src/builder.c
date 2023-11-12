#include "builder.h"
#include "color.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VICTORY_POINTS 20

struct builder_t{
    char level;
    int points;
    struct buildcost_t ressource;
    struct buildcost_t production;


};


struct builder_t game_builders[MAX_BUILDERS];
int nb_builders; 


/** Initializes the builders depending on an integer `seed`.
Can be called multiple times. Can also do nothing. */
void init_builders(unsigned int seed){
    srand(seed);
    struct builder_t init ; //situé ds le .h
    nb_builders= (rand()% MAX_BUILDERS);
     for( int i=0; i< nb_builders;++i){ 
        game_builders[i]= init;
        game_builders[i].level= rand() % NUM_LEVELS;
        game_builders[i].points=rand() % (VICTORY_POINTS);
        game_builders[i].ressource.c= rand()% MAX_COLORS;
        game_builders[i].ressource.n=rand()%2 +1;
        game_builders[i].production.c= (rand()*2)% MAX_COLORS,
        game_builders[i].production.n=2*rand() % 2 +1;
    }
}

/** Returns the total number of builders in the game. */
unsigned int num_builders(){
    return nb_builders;
}

/** Returns the `index`-th builder and NULL if it does not exist. */
struct builder_t* make_builder(unsigned int index){
    if (index < nb_builders){
        return &game_builders[index];
    }
    return NULL;
}

/** Returns the level of the builder. */
unsigned int builder_level(const struct builder_t* g){
    return g->level;
}

/** Returns the number of points of the builder. */
unsigned int builder_points(const struct builder_t* g){
    return g->points;
}

/** Returns the cost that must be payed in order to hire this builder. */
struct buildcost_t builder_requires(const struct builder_t* g){
    return g->ressource;
}

/** Returns the cost of the tokens that can be produced by this builder. */
struct buildcost_t builder_provides(const struct builder_t* g){
    return g->production;
}

// ADD THE NUMBER OF POINTS THAT WE CAN GET WITH THIS BUILDER
int builder_t_equals( struct builder_t builder1,  struct builder_t builder2){
    for (int i=0; i<MAX_BUILDERS; ++i){
        if (builder1.level != builder2.level){
            return 0;
        }
        if (builder1.points != builder2.points){
            return 0;
        }
        if ((builder1.ressource.c != builder2.ressource.c)||(builder1.ressource.n!= builder2.ressource.n)){
            return 0;
        }
        if ((builder1.production.c != builder2.production.c)||(builder1.production.n!= builder2.production.n)){
            return 0;
        }

    }
    return builder1.points;
}

/** Displays the builder on the stdout, after a possible prefix.
    Example : builder_display(g, "    - ") displays on the screen :
    - Builder(lvl=1,cost=1W,prod=1B)
*/
void builder_display(const struct builder_t* g, const char* prefix){
    printf("%s Builder(lvl= %d, cost=%d %s, prod= %d %s \n", prefix ,g->level,g->ressource.n,color_to_short_string(g->ressource.c), g->production.n,color_to_short_string(g->production.c) );
}
