
#include "token.h"
#include "color.h"
#include "builder.h"
#include "game.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int test_builder(){
  init_builders();
  for(unsigned int=0; i<MAX_BUILDERS; ++i){
    if (make_builder(i)){
     builder_display(make_builder(i), " \n Builder: ");
    }
  }
  return 1;
}
