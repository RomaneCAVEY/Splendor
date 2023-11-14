#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "token.h"
#include "builder.h"
#include "second_token.h"



struct token_t all_tockens[NUM_TOKENS];

struct token_t create_simple_token(enum color_t c){
    struct token_t token;
    for (int i=0; i<NUM_COLORS; ++i){
        token.c[i]= 0;
    }
    token.c[c]=1;
    return token;
    /*for (int i=0; i<NUM_COLORS; ++i){
        printf("%d",token.c[i]);
    }*/
}


struct token_t create_complex_token(unsigned int c[NUM_COLORS]){
    struct token_t token;
    for (int i=0; i<NUM_COLORS; ++i){
        token.c[i]= c[i];
    }
    return token;
}



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


struct token_t* token_get_adress(int i){
    return &all_tockens[i];

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



// Initialiser les tokens
struct token_t* init_all_tokens(){
    srand(SEED);
    for (int i=0; i< NUM_TOKENS; ++i){
        if (rand()%2 ==0){
            struct token_t t= create_simple_token(rand() %NUM_COLORS);
            all_tockens[i]=t;

        }
        else{
            unsigned int c[NUM_COLORS];
            c[rand()%NUM_COLORS]=1;
            c[rand()%NUM_COLORS]+=1;
            struct token_t t= create_complex_token(c);
            all_tockens[i]=t;

        }

    }
    return all_tockens;
}