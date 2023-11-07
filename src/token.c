#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "token.h"
#include "builder.h"


struct token_t create_simple_token(enum color_t c){
    struct token_t token;
    for (int i=0; i<NUM_COLORS; ++i){
        token.c[i]= 0;
    }
    token.c[c]=1;
    return token;
    for (int i=0; i<NUM_COLORS; ++i){
        printf("%d",token.c[i]);
    }
}


struct token_t create_complex_token(unsigned int c[NUM_COLORS]){
    struct token_t token;
    for (int i=0; i<NUM_COLORS; ++i){
        token.c[i]= c[i];
    }
    return token;}


struct builder{
    char level;
    int points;
    struct buildcost_t ressource;
    struct buildcost_t production;


};
