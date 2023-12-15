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
	}
}


skill token_has_the_power_i(struct token_t* token, int index){
	int count=0;
	while ( token_equals(*token, *token_power[count].token) && count<MAX_BUILDERS)
	{
		count++;
	}
	return token_power[count].powers[index];
}