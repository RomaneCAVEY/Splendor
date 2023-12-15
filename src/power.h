#include "builder.h"
#include "game.h"
#include "builder.h"
#include "guild.h"
#include "player.h"
#include "second_token.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_POWER 5


enum power{
    PANIC_MARKET,
    PANIC_GUILD,
    TOKEN_STEAL,
    TURN_STOLEN,
    MASTER_HAND,
};

struct game{
	int nbtour;
	struct player players[NB_PLAYERS];
	struct guild guild;
	struct market market; 
	void* ressource;
};



typedef int (*skill)(int current_player, struct player players[NB_PLAYERS], void* ressource);


const char * power_to_string(enum power power);


/**Init all the power*/
void init_power();




/**
Pick an available token market and move it in a random 
empty place of the market
*/
int panic_market(int current_player, struct player players[NB_PLAYERS], void* ressource);


/**
Current player can steal a token to the other player
*/
int token_steal(int current_player, struct player players[NB_PLAYERS], void* ressource);


/**


The player can take off one of the player of the guild and 
remplace it by a new one
*/
int guild_panic(int current_player, struct player players[NB_PLAYERS], void* ressource);


/**
Play again, new turn of the player
*/

int steal_turn(int current_player, struct player players[NB_PLAYERS], void* ressource);

/**
After hiring this architect, the player can take a token of one of the resources produced by the architect from the market.
*/

int master_hand(int current_player, struct player players[NB_PLAYERS], void* ressource);


extern skill skills[5]={
	panic_market,
	guild_panic,
	token_steal,
	steal_turn,
	master_hand
};


/**
return the power
*/
skill give_the_power(int index);