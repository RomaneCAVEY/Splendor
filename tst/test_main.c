#ifndef  __TEST_H__
#define __TEST_H__

#include "builder.h"
#include "test.h"
#include "token.h"
#include "color.h"
#include "player.h"
#include "game.h"
#include "player.h"
#include "second_token.h"
#include "second_builder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SEED 0

#define MAX_TURN 40
#define NB_MIN_PARAM 1
#define NB_PLAYERS 2


struct player players[NB_PLAYERS];


int test_builder()
{
  init_builders(SEED);
  for(unsigned int  i =0; i<MAX_BUILDERS; ++i){
    if (make_builder(i)){
     builder_display(make_builder(i), " \n Builder: ");
     printf("\n\n");
    }
  }
     printf("test passed\n");
  return 0;
}


int test_main()
{
    struct player player;
    int rang=get_random_player(NB_PLAYERS);
    player=players[rang];
    printf(" adress of player 1: %p", &player);
    player= players[next_player(NB_PLAYERS, rang)];
    return 0; 
}

int test_init(){
    init_player();
    init_all_tokens();
    init_builders(SEED);

    printf("====VOICI LES TOKENS DE LA PARTIE====\n");
    for (int i; i < NUM_TOKENS; ++i ){
        if((make_token(i))){
        token_display(*(make_token(i)),"");
        }
    }
    printf("====VOICI LES BUILDERS DE LA PARTIE====\n");
    for (int i; i < MAX_BUILDERS; ++i ){
        builder_display(make_builder(i),"");
    }   
    return 0; 

}

int test_display(){
  printf("====================================\n");
  init_builders(SEED);
  printf("%d \n",num_builders());
  for (unsigned int i=0; i< (MAX_BUILDERS-1) ;++i ){
      printf("====================================\n");
      printf("This is the builder of the index %d : \n \n", i);
      builder_display(make_builder(i), "-Here");
  }
      
    return 0;

}


int token_use()
{
    init_all_tokens();
    for (int i=0; i< NUM_TOKENS; ++i){
        printf("This is a token from the game \n");
        if(make_token(i)){
        token_display(*make_token(i), "this is a token");
        }
    }
    return 0;
}

int test_token_use(){
    printf ("\n this is a test: \n");
    enum color_t c= GREEN;
    struct token_t t=create_simple_token(c);
    const char* prefix= "-";
    token_display(t,prefix);
    return 0;

}

int test_new_market(int seed){
    srand(seed);
    int permutation[NUM_TOKENS]={};
    for (unsigned int i=0; i< NUM_TOKENS; i++){
        permutation[i]=(i+4)%NUM_TOKENS;
    }
    init_market(int *permutation);
    return 1
}

#endif