#ifndef __SUPER_BUILDER_H__
#define __SUPER_BUILDER_H__

#include"builder.h"
#include "power.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct builder_power{
	struct builder_t* builder;
	skill powers[NUM_POWER];
};

/**Init the powers of the builders*/
void  init_power_builders();

/**
Return the skill at place i in the tab of power of the builder builder
*/
skill builder_has_the_power_i(struct builder_t* builder, int index);


/**
Execute all the power of the current player 
*/
void execute_builder_power(int current, struct player players[NB_PLAYERS],struct builder_t* builder,struct guild_t *guild, struct market_t *market);

#endif