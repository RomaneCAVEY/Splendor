#include "token.h"
#include "builder.h"

struct token_t create_simple_token(enum color_t c){
    struct token_t token;
    token.c[c]=1;
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
    char level;
    int points;
    struct token_t ressource;
    struct token_t production;


};

struct market{
    int nbr_token;
    struct token_t token_in_market; /*Le market est du type [0,1,3,...,NUM_COLORS] avec chaque position correspondant à la couleur d'un jeton*/

};

struct guilde{
    int nbr_builder;
    struct builder builder_in_guilde[MAX_BUILDERS];

};

