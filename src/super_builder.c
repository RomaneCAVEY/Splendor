#include "super_builder.h"
#include "builder.h"
#include "guild.h"
#include "market.h"
#include "player.h"
#include "power.h"




struct builder_power builder_power[MAX_BUILDERS]={};



void init_power_builders(){
	srand(0);
	for (unsigned int i=0; i< num_builders(); i++){
		if (make_builder(i)){
		builder_power[i].builder= make_builder(i);
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
}


skill builder_has_the_power_i(struct builder_t* builder, int i){

	for (int index = 0 ; index < MAX_BUILDERS; ++index)
	{
		if (builder_power[index].builder == builder)
		{
			return builder_power[index].powers[i];
		}
	}
	return NULL;
}

void execute_builder_power(int current, struct player players[NB_PLAYERS],struct builder_t* builder,struct guild_t *guild, struct market_t *market){
	int flag = 0;
	for (enum power_id power_id = PANIC_MARKET ; power_id<= MASTER_HAND; power_id++){
		skill skill = builder_has_the_power_i(builder,power_id);
		if (power_id == TURN_STOLEN) 
			continue;
		if (skill){
			skill(current,players,builder,market,guild);
		}
	}
}