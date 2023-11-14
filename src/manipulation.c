#include "token.h"
#include "builder.h"
#include "color.h"
#include <stdio.h>
#include <stdlib.h>




/*return 0 if the token is simple and 1 otherwise*/
int is_complex(struct token_t t){
    int count=0;
    for (int i=0; i<NUM_COLORS; ++i){
        count= count + t.c[i];
        if (count>1) return 1;
    }
    return 0;
}


 /*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct token_t *token_player[], struct builder_t *b)
{
    struct buildcost_t cost= builder_requires(b);
    int count_desired_color=0;
    int count_just_desired_color=0;
    for (int i=0; i < NUM_TOKENS; ++i){
        struct token_t t = *token_player[i];
        count_desired_color = count_desired_color +t.c[cost.c];
        if (is_complex(t)){
            if (t.c[cost.c] == 2){
                count_just_desired_color= count_desired_color + 2;
            }
        count_just_desired_color = count_just_desired_color + 1;
        }
    }
    if (count_desired_color == cost.n){
        return 1;
    }

    if (count_desired_color > cost.n) return 2;

    else {
        return 0;
        }
}