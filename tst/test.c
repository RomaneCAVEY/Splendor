#include "builder.h"
#include "token.h"
#include "color.h"
#include "player.h"
#include "game.h"
#include "player.h"
#include "second_token.h"
#include "second_builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test.h"
#define SEED 0

int main(int argc, char* argv[])
{   
    if (argc< 1){
        printf("too few arguments");
    }
    else {
    printf("arguments took: %s", argv[1]);
    }
    printf("Voici les tests: \n \n");
    if(token_use()){
        printf("\n \n ==========================================");
        printf("test passed");
        printf("\n \n ==========================================");
    }
    else {printf("test failed");
    }
    if(test_init()){
        printf("\n \n ==========================================");
        printf("test passed");
        printf("\n \n ==========================================");
        }
    else {printf("test failed");
    }

    if(test_builder()){
        printf("\n \n ==========================================");
        printf("test passed");
        printf("\n \n ==========================================");
        }
    else {printf("test failed");
    }
    if(test_main()){
        printf("\n \n ==========================================");
        printf("test passed");
        printf("\n \n ==========================================");
        }
    else {printf("test failed");
    }
    if(test_init()){
        printf("\n \n ==========================================");
        printf("test passed");
        printf("\n \n ==========================================");
        }
    else {printf("test failed");
    }
    if(test_display()){
        printf("\n \n ==========================================");
        printf("test passed");
        printf("\n \n ==========================================");
        }
    else {printf("test failed");
    }

    if(token_use()){
        printf("\n \n ==========================================");
        printf("test passed");
        printf("\n \n ==========================================");
        }
    else {printf("test failed");
    }
    return 0;
}







