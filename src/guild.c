#include "guild.h"
#include "stack.h"
struct guild guild={};
/**
Init the guild with random value for builders
*/
void init_guild() {
    guild.nb_builder = num_builders();
    for ( int i = 0; i < guild.nb_builder; ++i) {
        if(make_builder(i)){
            guild.builders[i]= make_builder(i);
        }
    }
    for (unsigned int i = 0; i < NUM_LEVELS; ++i) {
        for (int j = 0; j < guild.nb_builder; ++j) {
            if (builder_level(guild.builders[j])==i && guild.builders[j]){
                stack_push(&guild.stack[i], guild.builders[j]);
            }
        }
       // printf("nb in the stack %d :  %d ",i, guild.stack[i].nb);
    }
    for (int level = 0; level <NUM_LEVELS; ++level) {
        for (int k = 0; k < MAX_BUILDERS_AVAILABLE_PER_LVL; ++k) {
            guild.builder_available[level*MAX_BUILDERS_AVAILABLE_PER_LVL+k]=stack_pop(&guild.stack[level]);
           

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
    if (guild.nb_builder >0){
    int level=builder_level(builder); 
    while (!builder_t_equals(guild.builder_available[i], builder) && i<MAX_BUILDERS) {
        i++;
    }
    int next=0;
    while (guild.stack[(level + next)%NUM_LEVELS].nb<0 && next< MAX_BUILDERS){
            next++;
    }
    if (next== MAX_BUILDERS){
         guild.builder_available[i]= NULL; 
    }
    else{
         guild.builder_available[i] = stack_pop(&guild.stack[level]);
    }
   
    guild.nb_builder -=1;
    }
}




struct builder_t * guild_builder_in_guild(unsigned index) {
    return guild.builder_available[index];
}


void guild_display(){
    printf("\n ########################################## \n");
    printf("\n GUILD DISPLAY \n ");
    if (guild.nb_builder>0){
        for ( int i=0; i< guild.nb_builder; i++){
            //printf("%p \n", &guild.builder_available[i] );
            if(&guild.builder_available[i]){
                builder_display(guild.builder_available[i], "this builder belongs to the guild \n");
            }
        }
    }
    else{
        printf("the guild is empty");
    }
    printf("\n ########################################## \n\n\n\n");
}

/** Add the builder bought in the guild to the player_builder
 */
void add_from_guild(int index, struct player players[NB_PLAYERS] , int current_player) {
    players[current_player].player_builder[players[current_player].nbr_builder] = guild_builder_in_guild(index);
    players[current_player].points += builder_points(guild.builder_available[index]);
    players[current_player].nbr_builder += 1;
}