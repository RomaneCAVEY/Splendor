#include "token.h"
#include "builder.h"
#include "color.h"
#include <stdio.h>
#include <stdlib.h>

struct token_t create_simple_token(enum color_t c);
void token_display(struct token_t t, const char* prefix);

int main (int argc, char* argv[]){
    printf ("this is a test");
    enum color_t c= GREEN;
    struct token_t t=create_simple_token(c);
    const char* prefix= "-";
    token_display(t,prefix);
    return 0;

}