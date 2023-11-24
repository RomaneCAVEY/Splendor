#include <stdlib.h>

#include <stdio.h>

#include <string.h>
#include "token.h"
#include "builder.h"

#include "second_token.h"


struct token_t all_tockens[NUM_TOKENS];

struct token_t* token_get_adress(int i) {
   return &all_tockens[i];

}



// Initialiser les tokens
void init_all_tokens() {
    srand(SEED);
    for (int i = 0; i < NUM_TOKENS; ++i) {
        if (rand() % 2 == 0) {
            struct token_t t = create_simple_token(rand() % NUM_COLORS);
            all_tockens[i] = t;

        } 
        else {
            unsigned int c[NUM_COLORS]={};
            c[rand() % NUM_COLORS] = 1;
            c[rand() % NUM_COLORS] += 1;
            struct token_t t = create_complex_token(c);
            all_tockens[i] = t;

        }

    }
}

/** Returns the `index`the token and NULL if it does not exist. */
struct token_t * make_token(unsigned int index) {
    if (index < NUM_TOKENS) {
        return &all_tockens[index];
    }
    return NULL;
}


int is_complex(struct token_t * t) {
    int count = 0;
    for (int i = 0; i < NUM_COLORS; ++i) {
        count = count + t -> c[i];
        if (count > 1) return 1;
    }
    return 0;

}