#ifndef __SUPER_TOKEN_H__
#define __SUPER_TOKEN_H__


#include"token.h"
#include "power.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct token_power{
	struct token_t* token;
	skill powers [NUM_POWER];
};


/**Init the powers of the tokens*/
void init_power_tokens();


/**
Return the power of the token at place i
*/
skill token_has_the_power_i(struct token_t* token, int index);


#endif