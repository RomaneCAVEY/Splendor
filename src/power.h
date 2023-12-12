#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


enum power{
    PANIC_MARKET,
    PANIC_GUILD,
    TOKEN_STEAL,
    TURN_STOLEN,
    MASTER_MAIN
};

const char * power_to_string(enum power power);

/**
Pick an available token market and move it in a random 
empty place of the market
*/
void panic_market();


/**
Current player can steal a token to the other player
*/
void token_steal(int current_player, int player_to_steal, struct player players[NB_PLAYERS]);

void gain_favor_with_builder(struct players[NB_PLAYERS], int current_player);

/**
The player can take off one of the player of the guild and 
remplace it by a new one
*/
void guild_panic();

void gain_favor_with_builder(struct players[NB_PLAYERS], int current_player);

void favor_steal(struct player players[NB_PLAYERS], int current_player);
