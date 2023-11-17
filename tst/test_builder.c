#include "token.h"
#include "color.h"
#include "manipulation.h"
#include "builder.h"
#include "game.h"
#include "player.h"
#include <stdio.h>

int main(int argc, char* argv[]){
  
init_builders(12);


    printf("This is the number of builder in the game: %d \n", num_builders());
  //  printf("This is the builder of the index %d \n", (make_builder(atoi(argv[1])))->level);
    return 0;
}
// pb avec le type abstrait , on peut passer que des pointeurs 