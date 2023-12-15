
#include "second_builder.h"

#define  NUM_POWER 5

const char * builders_powers[MAX_BUILDERS][NUM_POWER] ={};



// Option: ADD THE NUMBER OF POINTS THAT WE CAN GET WITH THIS BUILDER
int builder_t_equals(struct builder_t * builder1, struct builder_t * builder2) {
    return (builder1==builder2);
}
