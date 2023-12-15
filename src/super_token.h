#ifndef __SUPER_TOKEN_H__
#define __SUPER_TOKEN_H__


#include "second_token.h"
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



#endif