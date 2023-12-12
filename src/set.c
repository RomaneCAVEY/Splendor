#include "set.h"
#include <stdio.h>

void set_display(struct set_t set){
    printf("SET DISPLAY \n");
    for (unsigned int k=0; k<NUM_COLORS;k++){
            printf("\n The value of color %s is %d \n\n ", color_to_short_string(k), set.ressource[k]);

    }
}

/**Creation of set*/
struct set_t create_simple_set(enum color_t c) {
    struct set_t set;
    for (int i = 0; i < NUM_COLORS; ++i) {
        set.ressource[i] = 0;
    }
    set.ressource[c] = 1;
    return set;
    /*for (int i=0; i<NUM_COLORS; ++i){
        printf("%d",token.c[i]);
    }*/
}

struct set_t create_complex_set(unsigned int c[NUM_COLORS]) {
    struct set_t set;
    for (int i = 0; i < NUM_COLORS; ++i) {
        set.ressource[i] = c[i];
    }
    return set;
}
