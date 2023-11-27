#ifndef __GUILD_H__
#define __GUILD_H__


#include"market.h"
#include "token.h"
#include "builder.h"
#include "token.h"
#include "color.h"
#include "stack.h"
#include "second_builder.h"
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <string.h>


struct guild{
    int nb_builder;
    struct builder_t* builders[MAX_BUILDERS]; //All the builder of the beginning
    struct builder_t* builder_available[MAX_BUILDERS];// The MAX_BUILDER_PER_LEVEL we can pick each turn
    struct stack_t stack[MAX_BUILDERS];
};

void init_guild();

/**
Init the guild with random value for builders
*/
void init_guild();

/**
Return 1 if the builder is available in the guile, else 0
*/
struct builder_t* guild_available_builder(int i);
int guild_nbr_builder();

void remove_builders_from_guild(struct builder_t * builder);

struct builder_t * guild_builder_in_guild(unsigned index);
#endif