#include "game.h"
#include "builder.h"
#include "guild.h"
#include "power.h"
#include "super_token.h"
#include "super_builder.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



/**
Remove token
*/
void remove_token(struct player players[NB_PLAYERS] , struct token_t *token, int current_player) {
    //token_display(*token, "THE ONE WE WANT TO DELETE");
    int verif=1;
    int index=0;
    for (int i=0; i<NUM_TOKENS;i++){
        while (!players[current_player].player_token[i] && i<NUM_TOKENS){
           i+=1;
        }
        if (i<NUM_TOKENS){
            verif= token_equals(*players[current_player].player_token[i], *token);
            if (verif){
                index=i;
            }
        }
    }

    if(index<NUM_TOKENS){
       // token_display( *players[current_player].player_token[i],"FIND: \n \n");
        players[current_player].player_token[index] = NULL;
    }
    else {
        printf("there is a problem!!!!!!!!!!! This token doesn't exist");
    }
	players[current_player].nbr_token-=1;
}
    





/*return NULL if the player can't pay for a builder or return 1 if the player can pay the exact price or return 2*/
int possibility_token_pay(struct player player, struct builder_t * b) {
    if(b){

        struct set_t cost_color= builder_requires(b);
        //tmp variable used in the loop to know the cost of the builder
        struct set_t count_color={};
        unsigned int count=0;

        //tmp variable used in the loop
        struct token_t * token ;
        struct set_t buildcost;

        // Try to pay with the builders of the player
        for (int i = 0; i <player.nbr_builder; ++i){
            if(player.player_builder[i]){
                buildcost=builder_provides(player.player_builder[i]);
                //Browse the table of the set of buildcost
                for (unsigned int k=0;k<NUM_COLORS; k++){
                        count_color.ressource[k] +=buildcost.ressource[k];
                }

            }
        }
        for (int i = 0; i <NUM_COLORS; ++i){
            if (count_color.ressource[i]==cost_color.ressource[i]){
                count+=1;
            }
        }
        if (count==NUM_COLORS){
            return 4;
        }

        // Try to pay the rest with the tokens of the player
        for (int i = 0; i <player.nbr_token; ++i){
            token = player.player_token[i];
            if (token){
                for (unsigned int k=0; k<NUM_COLORS;k++){
            		count_color.ressource[k]+=token->s.ressource[k];
                }
            }
            
        }
        //End of the loop, check if it's possible to pay
        //set_display(cost_color);
        for (unsigned int k=0; k<NUM_COLORS;k++){
            //printf("\n the value of color %s is %d \n\n ", color_to_short_string(k), count_color.ressource[k]);
            if (count_color.ressource[k]<cost_color.ressource[k]){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}


//Pay the builder with the tokens of the player, remove the token used to pay and put the token on the market
int token_pay(struct builder_t * builder, struct player players[NB_PLAYERS], int current_player, struct market_t* market) {
    if (possibility_token_pay(players[current_player], builder)==4){
        return 1;
    }

    
    struct set_t cost_color= builder_requires(builder);
    //tmp variable used in the loop to know the cost of the builder
    unsigned int count_color[NUM_COLORS]={};

    //tmp variable used in the loop
    struct token_t * token ;
    struct set_t buildcost;


    //Pay what you can with the builder
        for (int i = 0; i <MAX_BUILDERS; ++i){
            if(players[current_player].player_builder[i]){
                buildcost=builder_provides(players[current_player].player_builder[i]);
                //Browse the table of the set of buildcost
                for (unsigned int k=0;k<NUM_COLORS; k++){
                        count_color[k] +=buildcost.ressource[k];
                
                }

            }
        }
	
    // Pay the rest with the tokens of the player
    for (int i = 0; i <NUM_TOKENS; ++i){
        int verif=1;
        token = players[current_player].player_token[i];
        if (token){
            int useful=0;
            for (int j=0; j<NUM_COLORS;j++){
                if (  (count_color[j]<cost_color.ressource[j]) &&  token->s.ressource[j] ){
                    useful=1;
                }

            }
            //if the value is useful to pay, we use it and add the other colors of it
            if(useful){
                for (unsigned int k=0; k<NUM_COLORS;k++){
                    count_color[k]+=token->s.ressource[k];
                }
				token_display(*token,  "Has to be removed to pay the builder");
				printf("\n");
                add_token_to_market(players[current_player].player_token[i], market);
                remove_token(players, players[current_player].player_token[i], current_player);
            }
                //Check if we reach the cost of the builder already
                for (unsigned int i=0; i<NUM_COLORS;i++){
                    if(count_color[i]<cost_color.ressource[i]){
                        verif=0;

                    }

                }
                if (verif){
                    return 1;
                }
        
        }
    }
    return 0;
}


/* Pay the builder game_builder[index] with the tokens of the players current_player
*/
void pay(struct player players[NB_PLAYERS], int index, int current, struct guild_t* guild, struct market_t* market){
    //printf(const char *restrict format, ...)
    token_pay(guild_builder_in_guild(index, guild), players, current, market);
    //printf(" \n payed \n ");
    add_from_guild(index, players, current,guild);
	struct builder_t *builder= guild_builder_in_guild(index,guild);
	remove_builders_from_guild(builder,guild);
	players[current].nbr_builder+=1;
	execute_builder_power(current, players, builder,guild,market);
    
}

/* Pick a token in the market, add in the player's token list, and remove it from the market
*/
void pick_tokens(int current_player, struct player players[NB_PLAYERS], int a, struct market_t* market,struct guild_t *guild){
    players[current_player].player_token[players[current_player].nbr_token] = token_get_adress(a);
	struct token_t *token=token_get_adress(a);
	execute_token_power(current_player, players, token,guild,market);
    //printf("adress of the token %d : %p",current_player, token_get_adress(a));
    players[current_player].nbr_token +=1;
    remove_token_from_market(token_in_market_is_available(a, market), market);

}
