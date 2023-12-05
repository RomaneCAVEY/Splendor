#include "test.h"
#include <stdio.h>




int main(int argc, char* argv[])
{   
    if (argc< 1){
        printf("too few arguments");
    }
    else {
    printf("arguments took: %s", argv[1]);
    }
    printf("Voici les tests: \n \n ******************** \n");
    if(!test_builder()){
        printf("\n \n ==========================================");
        printf("test builder : ");
        printf("test passed");
    }
    else {printf("test failed");
    }
    printf("\n \n ========================================== \n \n");
    if(!test_main()){
        printf("test main: \n");
        printf("test passed");
    }
    else {printf("test failed");
    }
    printf("\n \n ========================================== \n \n");
    
    if(!test_init()){
        printf("test init() \n");
        
        printf("test passed");
        }
    else {printf("test failed");
    }
    printf("\n \n ========================================== \n \n");
    if(!test_display()){
        printf("test display \n");
        printf("test passed");
        }
    else {printf("test failed");
    }
    printf("\n \n ========================================== \n \n");
    if(!token_use()){
        printf("test token use \n");
        printf("test passed");
        }
    else {printf("test failed");
    }
    printf("\n \n ========================================== \n \n");
    if(!test_token_use()){
        printf("test_token_use \n");
        printf("test passed");
        }
    else {printf("test failed");
    }
    return 0;
}







