#include "token.h"
#include "builder.h"
#include "color.h"
#include <stdio.h>
#include <stdlib.h>


const char* color_to_short_string(enum color_t c);


/** Compares the two tokens `t1` and `t2` and returns a boolean
    telling whether they are equal or different. */
int token_equals(const struct token_t t1, const struct token_t t2){
    for (int i=0; i<NUM_COLORS; ++i){
        if (t1.c[i]!=t2.c[i]){
            
            return 0;

        }
    }
    return 1;
}


/** Display the token on the stdout, after a possible prefix.
    Example : token_display(g, "    - ") displays on the screen :
    - Token(B=1,W=5)
*/
void token_display(struct token_t t, const char* prefix){
    printf("%s Token(", prefix);
    for (int i=0; i<NUM_COLORS; ++i){
        if (t.c[i]>0){
    printf(" %s = %d, ",color_to_short_string(i), t.c[i]);
         }
    }
    printf("),");

}

/*return 0 if the token is simple and 1 otherwise*/
int is_complex(struct token_t t)
{
    int count=0;
    for (int i=0; i<NUM_COLORS; ++i){
        count= count + t.c[i];
        if (count>1) return 1;
    }
    return 0;
}


 /*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 0*/
int token_pay(struct token_t t_player[], struct builder_t* b)
{
    struct buildcost_t cost= builder_requires(b);
    int count_desired_color=0;
    int count_just_desired_color=0;
    for (int i=0; i < NPLAYER; ++i){
        count_desired_color = count_desired_color + t_player[i][cost.c]
        if (is_complex(t_player[i])){
            if (t_player[i][cost.c] == 2){
                count_just_desired= count_desired_color + 2;
            }
        count_just_desired_color = count_just_desired_color + 1;
        }
    }
    if (count_desired_color <= cost.n){
        return NULL;
    }

    if (count_desired_color >= cost.n) return 1;

    if (count_desired_color < cost.n) return 0;

}

