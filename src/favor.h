#ifndef __FAVOR_H__
#define __FAVOR_H__


#include "guild.h"
#include "market.h"
#include "game.h"

void builder_guild_renew(int level_choosen, struct guild* guild);

int pick_any_token_in_market(int current_player, struct player players[NB_PLAYERS], int a, struct market* market);


#endif