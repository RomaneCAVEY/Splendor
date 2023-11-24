#include"market.h"
#include"guild.h"
#include "token.h"
#include "builder.h"
#include "token.h"
#include "game.h"
#include "color.h"
#include "second_builder.h"
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <string.h>


struct guild{
    int nbr_builder;
    struct builder_stack stack;
};
void init_guild();

struct guild guild;
/**
Init the guild with random value for builders
*/
void init_guild();

/**
Return 1 if the builder is available in the guile, else 0
*/
int is_guild_builder_in_guild(int i);

void remove_builders_from_guild(struct builder_t * builder);

struct builder_t * guild_builder_in_guild(unsigned index, int level);
