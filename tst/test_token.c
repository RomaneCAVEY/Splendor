#include <token.h>
#include <second_token.h>
#include <builder.h>
#include <stdio.h>
struct token_t create_simple_token(enum color_t c);
struct token_t create_complex_token(unsigned int c[NUM_COLORS]);
struct builder;

int test_token(){
    init_all_tokens();
    for (int i=0; i< NUM_TOKENS; ++i){
        printf("This is a token from the game \n");
        token_display(*make_token(i), "this is a token");
    }
    printf("test_token passed");
    return 1;
}