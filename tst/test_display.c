#include "second_token.h"
#include "second_builder.h"
#include "token.h"
#include "color.h"
#include "manipulation.h"
#include "builder.h"  
#include <stdio.h>

int main(int argc, char* argv[]){
  printf("====================================\n");
    
  init_builders(1047);
  printf("%d \n",num_builders());
  for (unsigned int i=0; i< num_builders() ;++i ){
      printf("====================================\n");
      builder_display(make_builder(i), "Voici ");

    }
  //  printf("This is the builder of the index %d \n", (make_builder(atoi(argv[1])))->level);
    return 0;

}