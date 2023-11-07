#include "token.h"
#include "builder.h"

struct token_t create_simple_token(enum color_t c){
    struct token_t token;
    token.c[0]=c;
    return token;

};


struct token_t create_complex_token(unsigned int c[NUM_COLORS]){
    struct token_t token;
    for (int i=0; i<NUM_COLORS; ++i){
        token.c[i]= c[i];
    }
    
    return token;
};

struct builder{
    int level;
    int points;
    enum color_t ressource;
    enum color_t production;


};
