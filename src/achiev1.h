#include "token.h"
#include "builder.h"
#include "token.h"
#include "color.h"
#include "second_builder.h"
#include "player.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

struct Element
{
    struct builder_t builder;
    struct Element *next;
};

struct Stack
{
    struct Element *first;
    int count;
};

void push(struct Stack stack, int elem){


}
struct builder_t pop(struct Stack stack){}