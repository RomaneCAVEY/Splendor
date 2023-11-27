#include "stack.h"
#include "builder.h"
#include <stdio.h>

struct stack_t stack_empty(){
    struct stack_t stack={};
    return stack;
}

void* pop( struct stack_t *stack)
{
    if (stack->nb == 0)
    {
        return NULL;
    }
    stack->nb--;
    void* out= stack->values[stack->head];
    stack->head--;
    return out;
}


void push(struct stack_t *stack, void* elem)
{
    if (stack->nb < (MAX_BUILDERS-1)){
        stack->head++;
        stack->values[stack->head]=elem;
    }
    else {
        printf("stack mistake in push function");
    }
}