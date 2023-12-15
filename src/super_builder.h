#ifndef __SUPER_BUILDER_H__
#define __SUPER_BUILDER_H__

#include"builder.h"
#include "power.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct builder_power{
	struct builder_t* buider;
	skill powers[NUM_POWER];
};

/**Init the powers of the builders*/
void  init_power_builders();

/**
Return the skill at place i in the tab of power of the builder builder
*/
skill builder_has_the_power_i(struct builder_t* builder, int index);



#endif