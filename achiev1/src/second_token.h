#ifndef __SECOND_TOKEN_H__
#define __SECOND_TOKEN_H__

#define SEED 0
/*
    get the adress of the token in all_tokens
*/
struct token_t* token_get_adress(int i); 


/*
    init NUM_TOKENS in all_tokens
*/
void init_all_tokens();

/*
    give the adress of the token at place index in all_tokens
*/
struct token_t* make_token(unsigned int index);



/*
    return 1 the token is complex, else 0
*/
int is_complex(struct token_t * t) ;
#endif