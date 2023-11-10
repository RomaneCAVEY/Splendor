<<<<<<< HEAD
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
=======
#include "../src/token.h"
#include "../src/builder.h"
#include "../src/color.h"
#include <stdio.h>
#include <stdlib.h>

>>>>>>> abb5a00b22c233ffac9b075a8471846b12e9fe26
