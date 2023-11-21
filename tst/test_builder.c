
#include "token.h"
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

int test_builder
{
  srand(NULL);
  init_builders(rand());
  for(unsigned int i =0; i<MAX_BUILDERS; ++i){
    if (make_builder(i)){
     builder_display(make_builder(i), " \n Builder: ");
    }
  }
     printf("test passed\n");
  return 0;
}
