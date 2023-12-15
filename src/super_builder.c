#include "super_builder.h"
#include "power.h"




struct builder_power builder_power[MAX_BUILDERS]={};



void init_power_builders(){
	srand(0);
	for (unsigned int i=0; i< MAX_BUILDERS; i++){
		builder_power[i].buider= make_builder(i);
		int level=builder_level(make_builder(i));
		int random=rand()%MAX_BUILDERS;
		if (random<(level+1)){
			builder_power[i].powers[1]=give_the_power(1);
		}
		random=rand()%MAX_BUILDERS;
		if (random<(level+1)){
			builder_power[i].powers[3]=give_the_power(3);
		}
		random=rand()%MAX_BUILDERS;
		if (random<(level+1)){
			builder_power[i].powers[4]=give_the_power(4);;
		}
	}
}


skill builder_has_the_power_i(struct builder_t* builder, int index){
	int count=0;
	while ( builder_t_equals(builder,builder_power[count].buider) && count<MAX_BUILDERS)
	{
		count++;
	}
	return builder_power[count].powers[index];
}