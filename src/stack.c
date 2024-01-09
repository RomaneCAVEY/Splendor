#include "stack.h"
#include "builder.h"
#include <stdio.h>

struct stack_t stack_empty(){
    struct stack_t stack={};
    return stack;
}

struct builder_t* stack_pop( struct stack_t *stack)
{
    if (stack->head == 0)
    {   
        printf("\n WARNING:empty stack! \n");
        return NULL;
    }
    stack->nb--;
	stack->head--;
    struct builder_t* out= stack->values[stack->head];
	stack->values[(stack->nb)+1]=NULL;
    
    return out;
}


void stack_push(struct stack_t *stack, void* elem)
{
    if (stack->nb < (MAX_BUILDERS-1)){
     
        stack->values[stack->head]=elem;
		stack->head++;
        stack->nb ++;
		//printf("ADRESSE: %p",elem);
    }
    else {
        printf("stack mistake in push function");
    }
}

void stack_display(struct stack_t stack){
	printf("This Stack has %d builders \n", stack.nb);
    for (int i=0; i<(stack.nb); i++){
        builder_display(stack.values[i], "this builder belong to the stack");

    }
}