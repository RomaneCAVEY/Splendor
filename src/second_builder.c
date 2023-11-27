#include "builder.h"

#include "color.h"
#include"guild.h"

#include "game.h"
#include "token.h"

#include "player.h"

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include "second_builder.h"


// Option: ADD THE NUMBER OF POINTS THAT WE CAN GET WITH THIS BUILDER
int builder_t_equals(struct builder_t * builder1, struct builder_t * builder2) {
    return (builder1==builder2);
}

/** Add the builder bought in the guild to the player_builder
 */
void add_from_guild(int index, struct player players[NB_PLAYERS] , int current_player) {
    players[current_player].player_builder[players[current_player].nbr_builder] = guild_builder_in_guild(index);
    players[current_player].points += builder_points(make_builder(index));
    players[current_player].nbr_builder += 1;
}