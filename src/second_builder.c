#include "builder.h"

#include "color.h"
#include"guild.h"

#include "game.h"
#include "token.h"

#include "player.h"

#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include "second_builder.h"

#define  NUM_POWER 5

const char * builders_powers[MAX_BUILDERS][NUM_POWER] ={};


// Option: ADD THE NUMBER OF POINTS THAT WE CAN GET WITH THIS BUILDER
int builder_t_equals(struct builder_t * builder1, struct builder_t * builder2) {
    return (builder1==builder2);
}


/*
struct builder_t* create_builder(){
    struct builder_t* builder;
    
}
*/