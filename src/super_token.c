#include"super_token.h"


struct token_power token_power[NUM_TOKENS]={};


void init_power_tokens(){
	srand(0);
	for (unsigned int i=0; i< NUM_TOKENS; i++){
		int random=rand()%NUM_TOKENS;
		if (!random){
			token_power[i].powers[0]=skills[0];
		}
		random=rand()%NUM_TOKENS;
		if (!random){
			token_power[i].powers[2]=skills[2];
		}
		token_power[i].token= make_token(i);
	}
}
