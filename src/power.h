#ifndef __POWER_H__
#define __POWER_H__

#include "builder.h"
#include "guild.h"
#include "market.h"
#include "player.h"
#include "second_token.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_POWER 5


enum power_id{
    PANIC_MARKET,
    PANIC_GUILD,
    TOKEN_STEAL,
    TURN_STOLEN,
    MASTER_HAND,
};




typedef int (*skill)(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild);


const char * power_to_string(enum power_id power);


/**Init all the power*/
void init_power();




/**
Pick an available token market and move it in a random 
empty place of the market
*/
int panic_market(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild);


/**
Current player can steal a token to the other player
*/
int token_steal(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild);

void gain_favor_with_builder(struct player players [NB_PLAYERS], int current_player);

/**


The player can take off one of the player of the guild and 
remplace it by a new one
*/
int guild_panic(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild);


/**
Play again, new turn of the player
*/

int steal_turn(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild);

/**
After hiring this architect, the player can take a token of one of the resources produced by the architect from the market.
*/

int master_hand(int current_player, struct player players[NB_PLAYERS], void* ressource,struct market_t *market,struct guild_t *guild);



/**
return the power of the index index
*/
skill give_the_power(enum power_id power_id);

void gain_favor_with_builder(struct player players[NB_PLAYERS], int current_player);

void favor_steal(struct player players[NB_PLAYERS], int current_player);





#endif