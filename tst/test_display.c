#include "second_token.h"
#include "second_builder.h"
#include "token.h"
#include "color.h"
#include "builder.h"  
#include <stdio.h>

int test_display(){
  printf("====================================\n");
    
  init_builders(1047);
  printf("%d \n",num_builders());
  for (unsigned int i=0; i< num_builders() ;++i ){
      printf("====================================\n");
      printf("This is the builder of the index %d \n", i);
      builder_display(make_builder(i), "- "Voici);
  }
      
    return 0;

}