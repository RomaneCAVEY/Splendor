#ifndef __SECOND_BUILDER_H__
#define __SECOND_BUILDER_H__

#include "builder.h"
#include "player.h"


//return 1 si builders are equal else 0
int builder_t_equals( struct builder_t *,  struct builder_t* );

void add_from_guild(int index, struct player* current_player);
#endif