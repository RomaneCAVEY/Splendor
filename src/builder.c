#include "builder.h"
#include "color.h"
#include "token.h"
#include <stdio.h>
#include <time.h>


struct builder_t{
    char level;
    int points;
    struct buildcost_t ressource;
    struct buildcost_t production;


};


    struct builder_t* game_builders[MAX_BUILDERS];


/** Initializes the builders depending on an integer `seed`.
Can be called multiple times. Can also do nothing. */
void init_builders(unsigned int seed){
    struct builder_t* init ;
     for( int i=0; i<MAX_BUILDERS;++i){ 
        game_builders[i]= init;
        int a= srand(seed ? atoi(seed) : time(NULL));
        game_builders[i]->level= a % NUM_LEVELS;
        game_builders[i]->points=0;
        game_builders[i]->ressource.c= a% MAX_COLORS;
        game_builders[i]->ressource.n=a;
        game_builders[i]->production.c= (a*2)% MAX_COLORS,
        game_builders[i]->production.n=2*a;
                
            }
            }

/** Returns the total number of builders in the game. */
unsigned int num_builders(){
    unsigned int count=0;
    for(int i=0; i<MAX_BUILDERS;++i){
        if (game_builders[i]){
            count+=1;
        }
    }
    return count;
}

/** Returns the `index`-th builder and NULL if it does not exist. */
struct builder_t* make_builder(unsigned int index){
    if (game_builders[index]){
        return game_builders[index];
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


/** Displays the builder on the stdout, after a possible prefix.
    Example : builder_display(g, "    - ") displays on the screen :
    - Builder(lvl=1,cost=1W,prod=1B)
*/
void builder_display(const struct builder_t* g, const char* prefix){
    printf("%s Builder(lvl= %d, cost=%d %s, prod= %d %s \n", prefix ,g->level,g->ressource.n,color_to_short_string(g->ressource.c), g->production.n,color_to_short_string(g->production.c) );
}
