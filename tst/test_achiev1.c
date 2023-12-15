#include"test_achiev1.h"

/*Test a permutation of the market*/
int test_new_market(int seed){
    srand(seed);
    int permutation[NUM_TOKENS]={};
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        permutation[i]=(i+4)%NUM_TOKENS;
    }
    init_market(permutation);
    return 1;
}


/*Test stack diplay of th guild*/
int stack(int seed){
    srand(seed);
    init_builders(seed);
    for (int i=0; i<NUM_LEVELS; i++){
        stack_display(guild_stack( i));
    }
    return 1;
}

int return_int(){

	return 12;
}
/*Test the market display*/
int market_display_test(){
    init_market();
    market_display();
    return 1;
}