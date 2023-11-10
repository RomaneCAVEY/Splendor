#include "token.h"
#include "color.h"
#include "builder.h"
#include <stdio.h>

int main(int argc, char* argv[]){
  
    struct builder_t t;
    struct builder* game_builders[MAX_BUILDERS];
    init_builders(12);

    printf("This is the number of builder in the game: %d \n", num_builders());
  //  printf("This is the builder of the index %d \n", (make_builder(atoi(argv[1])))->level);
    return 0;
}