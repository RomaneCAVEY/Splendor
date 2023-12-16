#include"test_achiev1.h"


/*Test a permutation of the market*/
int test_new_market(int seed){
	struct market_t market={};
    srand(seed);
	init_permutation();
    init_market(&market);
    return 1;
}


/*Test stack diplay of th guild*/
int stack(int seed){
    srand(seed);
	struct guild_t guild={};
	init_guild(&guild);
    init_builders(seed);
    for (int i=0; i<NUM_LEVELS; i++){
        stack_display(guild_stack(i,&guild));
    }
    return 1;
}

/*Test the market display*/
int market_display_test(){
	struct market_t market={};
    srand(0);
	init_permutation();
    init_market(&market);
    market_display(&market);
    return 1;
}