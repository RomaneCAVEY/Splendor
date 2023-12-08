#include "set.h"
#include <stdio.h>

void set_display(struct set_t set){
    printf("SET DISPLAY \n");
    for (unsigned int k=0; k<NUM_COLORS;k++){
            printf("\n The value of color %s is %d \n\n ", color_to_short_string(k), set.ressource[k]);

    }
}