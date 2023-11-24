//
// @filename achiev2.c
// @date ven. 24 nov. 2023 14:24:53 CET
// @author Romane Cavey <romane.cavey@enseirb-matmeca.fr>
// @brief ...
//
#include "token.refactor.h"
#include "builder.refactor.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


  /*Token.c*/
struct token_t create_simple_token(enum color_t c) {
    struct token_t token;
    for (int i = 0; i < NUM_COLORS; ++i) {
        token.s.ressource[i] = 0;
    }
    token.s.ressource[c] = 1;
    return token;
    /*for (int i=0; i<NUM_COLORS; ++i){
        printf("%d",token.c[i]);
    }*/
}

struct token_t create_complex_token(struct set_t s) {
    struct token_t token;
    for (int i = 0; i < NUM_COLORS; ++i) {
        token.s.ressource[i] = s.ressource[i];
    }
    return token;
}

/** Compares the two tokens `t1` and `t2` and returns a boolean
    telling whether they are equal or different. */
int token_equals(const struct token_t t1, const struct token_t t2) {
    for (int i = 0; i < NUM_COLORS; ++i) {
        if (t1.s.ressource[i] != t2.s.ressource[i]) {

            return 0;

        }
    }
    return 1;
}

/** Display the token on the stdout, after a possible prefix.
    Example : token_display(g, "    - ") displays on the screen :
    - Token(B=1,W=5)
*/
void token_display(struct token_t t, const char * prefix) {
    printf("%s Token (", prefix);
    for (int i = 0; i < NUM_COLORS; ++i) {
            if (t.s.ressource[i]) {
                printf(" ( %s = %d) , ", color_to_short_string(i), t.s.ressource[i]);
                //printf(" with the following address: %p", &t);
            }
    }
    printf(")\n");

}




/* buider.c*/


struct builder_t{
    char level;
    int points;
    struct set_t ressource;
    struct set_t production;

};

struct builder_t game_builders[MAX_BUILDERS];
unsigned int nb_builders;

/** Initializes the builders depending on an integer `seed`.
Can be called multiple times. Can also do nothing. */
void init_builders(unsigned int seed) {
    srand(seed);
    int ressource1=0;
    int ressource2=0;
    int produce2=0;
    int produce1=0;

    nb_builders = 5 + (rand() % (MAX_BUILDERS - 1));
    for (unsigned int i = 0; i < nb_builders; ++i) {
        game_builders[i].level = rand() % NUM_LEVELS;
        game_builders[i].points = rand() % (VICTORY_POINTS);
        for (unsigned int i = 0; i < 2; ++i){
            int ressource1=rand()% NUM_COLORS;
            int ressource2=rand()% NUM_COLORS;
        }
        for (unsigned int i = 0; i < 2; ++i){
            int produce1=rand()% NUM_COLORS;
            int produce2=rand()% NUM_COLORS;
        }
            game_builders[i].ressource.ressource[ressource1] +=1;
            game_builders[i].ressource.ressource[ressource2] +=1;
            game_builders[i].production.ressource[produce1] +=1;
            game_builders[i].production.ressource[produce1] +=1;
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

void builder_display(const struct builder_t * g, const char * prefix) {
    if (g) {
        printf("%s Builder(lvl= %d, cost= ",prefix, g -> level);
        for (unsigned int i=0; i<NUM_COLORS; ++i){
            if (g -> ressource.ressource[i]>0){
                printf("%d=%s",  g -> ressource.ressource[i], color_to_short_string(g -> ressource.ressource[i]));

            }

        }
        printf(", prod: ");
         for (unsigned int i=0; i<NUM_COLORS; ++i){
            if (g -> ressource.ressource[i]>0){
                printf("%d %s",  g -> production.ressource[i], color_to_short_string(g -> production.ressource[i]));
            }

        }
        printf(" ,points = %d) \n \n", g->points);
    } 
    else {
        printf("NULL");
    }
}


