#ifndef __GUILD_H__
#define __GUILD_H__


#include"market.h"
#include "stack.h"
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef MAX_BUILDERS_AVAILABLE_PER_LVL
#define MAX_BUILDERS_AVAILABLE_PER_LVL 3
#endif


struct guild{
    int nb_builder;
    struct builder_t* builders[MAX_BUILDERS]; //All the builder of the beginning
    struct builder_t* builder_available[MAX_BUILDERS];// The MAX_BUILDER_PER_LEVEL we can pick each turn
    struct stack_t stack[NUM_LEVELS];
};

void init_guild();
/** Add the builder bought in the guild to the player_builder
 */
void add_from_guild(int index, struct player players[NB_PLAYERS] , int current_player);
/**
Init the guild with random value for builders
*/
void init_guild();

/**
Return 1 if the builder is available in the guile, else 0
*/
struct builder_t* guild_available_builder(int i);
int guild_nbr_builder();

/**
Remove the buider we bought from the guild, pick another one to complete the guild, with a builder
of the same level if it's possible
*/
void remove_builders_from_guild(struct builder_t * builder);

struct builder_t * guild_builder_in_guild(unsigned index);
/**
Display the available builders of the guild
*/
void guild_display();

/** Add the builder bought in the guild to the player_builder
 */
void add_from_guild(int index, struct player players[NB_PLAYERS] , int current_player);



#endif