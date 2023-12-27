#include <threads.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "builder.h"
#include "power.h"
#include "guild.h"
#include "player.h"
#include "game.h"
#include "super_builder.h"
#include "market.h"
#include "super_token.h"
#include "favor.h"
#include "token.h"
#define NB_PLAYERS 2

struct guild_t guild={};
struct market_t market={};
struct player players[NB_PLAYERS];

int main(int argc, char *argv[]){

    int max_turn;
    int seed;
    int seed_builder;
    int opt;
	int display;

    max_turn = 0;
    seed = 0;
    seed_builder = 0;
	display=0;
    while ((opt= getopt(argc, argv, "s:m:c:d:"))!=(-1)) {
        switch (opt) {
            case 's':
                seed= atoi(optarg);
                break;
            case 'm':
                max_turn = atoi(optarg);
                break;
            case 'c':
                seed_builder = atoi(optarg);
                break;
			case 'd':
				display=atoi(optarg);
				break;
                
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-s seed] [-m max_turn]  [-c seed_builder] [-d display] \n",argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    if (optind > argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }
    printf("max_turn=%d; seed=%d; seed_builder=%d , display=%d \n", max_turn, seed, seed_builder,display);
    srand(seed);
    //Init player
    for (int i = 0; i < NB_PLAYERS; i++) {
        players[i] = init_player();
        players[i].index = i;
    }
    int current_player = (get_random_player(NB_PLAYERS));
	players[(current_player+1)%NB_PLAYERS].favor_nbr+=1;
    //Init market and guild    
    init_permutation();
    // Init all_tokens
    init_all_tokens(); 
    //Init all_builders 
    init_builders(seed_builder);
    // init the guild
    init_guild(&guild); 
	//guild_display(&guild);
    // init the market
   	init_market(&market);
	//market_display(&market);
	init_power_builders();
	init_power_tokens();
    int nb_turns_not_played = 0;
    int nb_turns = 0;
    printf("initialisation over \n");
    printf(" ********************************** \n");
    //int c=0;
    while (!(has_won(players) && (nb_turns_not_played < 2)) && nb_turns < max_turn) {
		printf(UGRN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" COLOR_RESET);
        printf(UGRN"This is the turn %d \n" COLOR_RESET, nb_turns);
        printf(UGRN"this is the points %d of the current player, player %d\n" COLOR_RESET, players[current_player].points,current_player);
		srand(0);
		int level_choosen=rand()%NUM_LEVELS;
        execute_favors(current_player, players, &market,&guild,level_choosen);
		int index=0;
        int possibility_to_pay=0;
		struct builder_t *builder=NULL;
        //printf("\n guild_nbr_builder %d \n", guild_nbr_builder(&guild));
        //guild_display(&guild);
        for ( int i = (num_builders()); i>(-1) ; i--) {
        //fprintf(stderr,"c:%d\n",c);
        // c+=1;
			//printf("\n num_builder is %d: \n", num_builders());
			//printf("\n This is player %d \n" , current_player);
            if (guild_available_builder(i, &guild)) {
				//builder_display(guild_available_builder(i, &guild), "\n Builder to check \n");
				//printf("This is the possibility to pay a builder of the player %d \n", possibility_token_pay(players[current_player], guild_available_builder(i, &guild)));
                if (possibility_token_pay(players[current_player], guild_available_builder(i, &guild))) {
                  
                    possibility_to_pay = possibility_token_pay(players[current_player], guild_available_builder(i, &guild));
                    index = i;
					builder=guild_available_builder(i, &guild);

					
					//printf("INDEX: %d \n",index);

                }
            }
        }
        if (display) {
		
			market_display(&market);
			guild_display(&guild);
			printf("this is the possibility to pay a builder is %d\n", possibility_to_pay);
			
		}
       
        

        //If we can build a builder then we do it
        if (possibility_to_pay) {
            //put in the market the tokens which were useful to pay the builder, except if they are builders
			builder_display(guild_available_builder(index, &guild), "\n THIS IS THE BUILDER WE WANT TO BUY: \n");
            pay(players,index, current_player,&guild,&market);
            printf("this is the points  %d of player %d\n", players[current_player].points,current_player);
            }
             
        //Else we pick some tokens if it's possible;
        else {
			//printf("PIOCHER DES TOKENS");
            //nb = number between 1 and 3 of tokens the player will pick from the market
            int nb = rand() % 3+1;
            //add = number of tokens we have already picked from the market amoung the nb tokens
            // int add=0;
            int random = rand() % NUM_TOKENS;
			int count=0;
			while(!token_in_market_is_available((random+count)%NUM_TOKENS,&market) && count<NUM_TOKENS){
				count++;
			}
				
			random=(random+count)%NUM_TOKENS;
            if (nb <= market_nbr_token(&market) && token_in_market_is_available(random,&market)) {
    
                    //printf("%d est aléatoire \n", nb);
                    //printf("there are %d tokens in the market \n",market_nbr_token());
                    tokens_connex(random, nb, current_player, players,&market,&guild);
                    
                }
            else {
                nb_turns_not_played = nb_turns_not_played + 1;
                }
        }
		if(display){
                   
                    player_display(players,current_player);
                    printf("\n");
				}
        //printf("PLAYER DISPLAY OF PLAYER %d \n", current_player);
        //player_display(players[current_player]);
        
        current_player=next_player(NB_PLAYERS, current_player);
        nb_turns += 1;
		//printf("THE INDEX IS :%d \n",index);
		skill steal_turn= builder_has_the_power_i(builder, TURN_STOLEN);
		if (steal_turn){
			current_player=steal_turn(current_player,players, NULL,&market,&guild);
		}
        

    }

   
    if (nb_turns_not_played >= 2){
        printf(UGRN"\n\n BOTH LOOSE \n\n" COLOR_RESET);
        return 0;

    }
    else{
        winner(players);
    }
    return 0;
}