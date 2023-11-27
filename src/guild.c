#include "guild.h"
#include "game.h"
#include "market.h"
#include "stack.h"
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

struct guild guild={};
/**
Init the guild with random value for builders
*/
void init_guild() {
    guild.nb_builder = num_builders();
    for (unsigned int i = 0; i < guild.nb_builder; ++i) {
         guild.builders[i]= make_builder(i);
    }
    for (int i = 0; i < NUM_LEVELS; ++i) {
        for (int j = 0; j < guild.nb_builder; ++j) {
            if (builder_level(guild.builders[j])==i){
                push(guild.stack[i], guild.builders[j]);
        }  
    }
    for (int level = 0; level <NUM_LEVELS; ++level) {
        for (int k = 0; k < MAX_BUILDERS_AVAILABLE_PER_LVL; ++k) {
            guild.builder_available[level*MAX_BUILDERS_AVAILABLE_PER_LVL+k]=pop(guild.stack[level]);

         }
    }
}
}

int guild_nbr_builder() {
    return guild.nb_builder;
}

struct builder_t* guild_available_builder(int i){
    return guild.builder_available[i];

}

void remove_builders_from_guild(struct builder_t * builder) {
    unsigned int i = 0;
    int level=builder_level(builder); 
    while (!builder_t_equals(guild.builder_available[level*i], builder) && i<3) {
        i++;
    }
    int next=0;
    while (!pop(guild.stack[level]) && next< MAX_BUILDERS){
        guild.builder_available[level*MAX_BUILDERS_AVAILABLE_PER_LVL] = pop(guild.stack[(level + next)%NUM_LEVELS]);
        next++;
    }
    guild.builder_available[level*MAX_BUILDERS_AVAILABLE_PER_LVL] = pop(guild.stack[level]);
    guild.nb_builder -=1;
}




struct builder_t * guild_builder_in_guild(unsigned index) {
    return guild.builder_available[index];
}
