#include"permutation.h"
#include <stdlib.h>

int permutation[NUM_TOKENS]={};

void init_permutation(){
    int random=rand();
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        permutation[i]=(i+random)%NUM_TOKENS;
    }
}

int make_permutation(int index){
    return permutation[index];
}