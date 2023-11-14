#include "../src/builder.h"
#include "../src/token.h"
#include "../src/color.h"
#include "../src/manipulation.h"
#include "../src/player.h"
#include "../src/game.h"
#include "../src/second_token.h"
#include "../src/second_builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
  init_builders(0);
  builder_display(&(game_builders[0]), "Premier builder");

  return 0;
}
