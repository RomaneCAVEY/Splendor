#include <token.h>
#include <builder.h>
#include <color.h>
#include <stdio.h>
#include <stdlib.h>

const char* color_to_short_string(enum color_t c);
struct token_t create_simple_token(enum color_t c);
void token_display(struct token_t t, const char* prefix);

int main (int argc, char* argv[]){
    enum color_t c= GREEN;
    struct token_t t=create_simple_token(c);
    for (int i=0; i<NUM_COLORS; ++i){
    printf("%d", t.c[i]);
         }
    const char* prefix= "Voici le";
    token_display(t,prefix);

}