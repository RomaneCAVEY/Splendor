#ifndef __STACK_H__
#define  __STACK_H__

#define VICTORY_POINTS 15
#ifndef NB_PLAYERS
#define NB_PLAYERS 2
#endif

#include "builder.h"
#include "token.h"
#include "color.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


struct stack_t{
    int nb;
    int head;
    struct builder_t* values[MAX_BUILDERS];
};

/**
Return an empty stack
*/
struct stack_t stack_empty();

/**
Pop a builder from the stack
*/
struct builder_t* stack_pop( struct stack_t *stack);

/**
Push a builder in the stack
*/
void stack_push(struct stack_t *stack, void* elem);


/**
Display the builders who are in the stack
*/
void stack_display(struct stack_t stack);

#endif