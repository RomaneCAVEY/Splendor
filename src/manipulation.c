#include "token.h"
#include "builder.h"
#include "color.h"



/** Compares the two tokens `t1` and `t2` and returns a boolean
    telling whether they are equal or different. */
int token_equals(const struct token_t t1, const struct token_t t2){
    for (int i=0; i<NUM_COLORS; ++i){
        if (t1[i]!=t2[i]){
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
    printf("%s Token(B=%d,W=%d)",prefix,t.c[],t.c[]);


}
