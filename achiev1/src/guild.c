#include"guild.h"
#include "game.h"
#include<market.h>
#include "token.h"
#include "builder.h"
#include "token.h"
#include "color.h"
#include "second_builder.h"
#include "second_token.h"
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
struct guild guild;
/**
Init the guild with random value for builders
*/
void init_guild() {
    guild.nbr_builder = num_builders();
    for (int i = 0; i < guild.nbr_builder; ++i) {
        int place= guild.builder_in_guild[builder_level(make_builder(i))].nbr_stack;
        guild.builder_in_guild[builder_level(make_builder(i))-1].stack[place]=make_builder(i);  
    }
}

/**
Return 1 if the builder is available in the guile, else 0
*/
int is_guild_builder_in_guild(int i) {
    if (guild.builder_in_guild[i]) {
        return 1;
    }
    return 0;

}

int guild_nbr_builder() {
    return guild.nbr_builder;
}


void remove_builders_from_guild(struct builder_t * builder) {
    unsigned int i = 0;
    int level=builder_level(builder); 
    while (!builder_t_equals(guild.builder_in_guild[level-1].stack[i], builder) && i<MAX_BUILDERS) {
        i++;
    }
    guild.builder_in_guild[level-1].stack[i] = NULL;
    guild.nbr_builder -=1;
    guild.builder_in_guild[level-1].nbr_stack-=1;
}


struct builder_t * guild_builder_in_guild(unsigned index, int level) {
    return guild.builder_in_guild[level].stack[index];
}
