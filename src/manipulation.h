#ifndef __MANIPULATION_H__
#define __MANIPULATION_H__


/*return 0 if the token is simple and 1 otherwise*/
int is_complex(struct token_t);


 /*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct token_t* token[], struct builder_t* );
#endif