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
Return the fonction of the ressources

skill give_the_power(int index);
*/


#endif