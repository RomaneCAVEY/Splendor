#include "stack.h"
void* pop( struct stack_t stack)
{
    if (stack.nb == 0)
    {
        return NULL;
    }
    return stack.values[stack.first];
}


void push(struct stack_t stack, void* elem)
{
   int i=0;
   while (stack.values[i]!= NULL){
    i++;
   }
   stack.values[i]=elem;
}