#include"super_token.h"
#include "token.h"
#include "power.h"

struct token_power token_power[NUM_TOKENS]={};


void init_power_tokens(){
	srand(0);
	for (unsigned int i=0; i< NUM_TOKENS; i++){
		int random=rand()%NUM_TOKENS;
		if (!random){
			token_power[i].powers[0]=give_the_power(0);;
		}
		random=rand()%NUM_TOKENS;
		if (!random){
			token_power[i].powers[2]=give_the_power(2);
		}
		token_power[i].token= make_token(i);
		random=rand()%2;
		if (random){
			token_power[i].powers[6]=give_the_power(6);
		}
	}
}


skill token_has_the_power_i(struct token_t* token, int i){


	for (int index = 0 ; index < NUM_TOKENS; ++index)
	{
		if (token_power[index].token == token)
		{
			return token_power[index].powers[i];
		}
	}
	return NULL;
}


void execute_token_power(int current, struct player players[NB_PLAYERS],struct token_t* token,struct guild_t *guild, struct market_t *market){
	for (enum power_id power_id = PANIC_MARKET ; power_id<= FAVOR_STEAL; power_id++){
		skill skill = token_has_the_power_i(token,power_id);
		if (power_id == TURN_STOLEN) 
			continue;
		if (skill){
			skill(current,players,token,market,guild);
		}
	}
}