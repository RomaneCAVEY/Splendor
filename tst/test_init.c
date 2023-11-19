#include "second_token.h"
#include "second_builder.h"
#include "token.h"
#include "color.h"
#include "builder.h"  
#include <stdio.h>
#ifndef SEED
  #define SEED 0
#endif


int main(int argc,char* argv[])
{
    init_all_tokens();
    for (int i; i < NUM_TOKENS; ++i ){
        token_display(*(make_token(i)),"");
    }
    return 0;
}