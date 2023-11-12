/** The number of tokens in play. */
#ifndef NUM_TOKENS
  #define NUM_TOKENS 25
#endif


/*return 0 if the token is simple and 1 otherwise*/
int is_complex(struct token_t);


 /*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct token_t , struct builder_t );