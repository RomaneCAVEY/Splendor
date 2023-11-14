#ifndef __SECOND_TOKEN_H__
#define __SECOND_TOKEN_H__

#define SEED 0
/*
    get the adress of the token
*/
struct token_t* token_get_adress(int i); 
struct token_t* init_all_tokens();
struct token_t* make_token(unsigned int index);
#endif