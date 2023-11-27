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
    void* values[MAX_BUILDERS];
};


struct stack_t stack_empty();

void* pop( struct stack_t *stack);


void push(struct stack_t *stack, void* elem);

#endif