#include"permutation.h"
<<<<<<< HEAD
=======
#include "token.h"
>>>>>>> achiev2
#include <stdlib.h>

int permutation[NUM_TOKENS]={};

<<<<<<< HEAD
void init_permutation(){
    int random=rand();
=======

void init_permutation(){
    int random= rand();
>>>>>>> achiev2
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        permutation[i]=(i+random)%NUM_TOKENS;
    }
}

int make_permutation(int index){
    return permutation[index];
<<<<<<< HEAD
=======

>>>>>>> achiev2
}