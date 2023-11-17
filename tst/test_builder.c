<<<<<<< HEAD
#include "../src/token.h"
#include "../src/color.h"
#include "../src/manipulation.h"
#include "../src/builder.h"
#include "../src/game.h"
#include "../src/player.h"
=======
#include "../src/builder.h"
#include "../src/token.h"
#include "../src/color.h"
#include "../src/manipulation.h"
#include "../src/player.h"
#include "../src/game.h"
#include "../src/second_token.h"
#include "../src/second_builder.h"
>>>>>>> refs/remotes/origin/master
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
<<<<<<< HEAD
  
init_builders(12);


    printf("This is the number of builder in the game: %d \n", num_builders());
  //  printf("This is the builder of the index %d \n", (make_builder(atoi(argv[1])))->level);
    return 0;
=======
  init_builders(0);
  builder_display(&(game_builders[0]), "Premier builder");

  return 0;
>>>>>>> refs/remotes/origin/master
}
