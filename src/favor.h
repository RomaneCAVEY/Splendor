#ifndef __FAVOR_H__
#define __FAVOR_H__


#include "game.h"

void builder_guild_renew(unsigned int level_choosen, struct guild_t* guild);

int pick_any_token_in_market(int current_player, struct player players[NB_PLAYERS], struct market_t* market,struct guild_t *guild);

void execute_favors(int current_player, struct player players[NB_PLAYERS],struct market_t *market,struct guild_t *guild,int level_choosen);
#endif