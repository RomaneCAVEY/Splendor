#include "builder.h"
#include "token.h"
#include "color.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#define SEED 0
#define MAX_TURN 40
#define VICTORY_POINTS 40
#define EXIT_FAILURE 7
#define NB_MIN_PARAM 3



struct player{
    struct token_t* player_token[NUM_TOKENS+MAX_BUILDERS];
    struct builder_t* player_builder[MAX_BUILDERS];
    int points;
    int nbr_token;
    int nbr_builder;

};


struct market{
    int nbr_token;
    int available_tokens[NUM_TOKENS]; /*Le market est du type [0,1,3,...,NUM_COLORS] avec chaque position correspondant à la couleur d'un jeton*/

};

struct guild{
    int nbr_builder;
    struct builder_t* builder_in_guild[MAX_BUILDERS];

};


void remove_token(struct token_t* tab[], const struct token_t token){
    int i=0;
    while(token_equals(token,*tab[i])){
        i++;
    }
     tab[i]=NULL;
}

//Pay the builder with the tokens of the player
void token_pay(struct builder_t *b, struct player player, struct market market)
{
    struct buildcost_t cost= builder_requires(b);
    int count=0;
    int i=0;
    while (i < (NUM_TOKENS+MAX_BUILDERS)){
        if(player.player_token[i]->c[cost.c]){
            market.available_tokens[market.nbr_token]=0;
            market.nbr_token= market.nbr_token +1;
            count= count+ player.player_token[i]->c[cost.c]; 
            if (i< NUM_TOKENS){
                remove_token( player.player_token,*player.player_token[i]);
            }

        }
    }
}

void remove_builders_from_guild(struct guild guild, struct buildcost_t builder){
    int i=0;
    while(!builder_t_equals(guild.builder_in_guild[i], builder)){
        i++;
    }
    guild.builder_in_guild[i]=NULL;
     



int has_won(struct player player1, struct player player2){
    if (player1.points >= VICTORY_POINTS || player2.points >= VICTORY_POINTS){
        return 1;
    }
    return 0;
}

struct player init_player(){
    struct player player;
    player.points=0;
    memset(player.player_token, 0, NUM_TOKENS+MAX_BUILDERS);
    memset(player.player_builder, 0, MAX_BUILDERS);
    return player;
}


//Declaration of some variables
struct player player1= init_player() ;
struct player player2= init_player();
struct builder_t* game_builders[MAX_BUILDERS];
struct token_t all_tockens[NUM_TOKENS];
struct token_t tokens_from_builders[MAX_BUILDERS];



struct player* get_random_player(){
    srand(SEED);
    struct player *player;
    int a= rand() % 2;
    if (a){
        player= & player2;
        return player;
    }
    player= & player1;
    return player;
      
}


void next_player(struct player* current_player){
    if (current_player==&player1){
        current_player=&player2;
    }
    current_player=&player1;
}





// Initialiser les tokens
struct token_t* init_all_tokens(){
    srand(SEED);
    for (int i=0; i< NUM_TOKENS; ++i){
        if (rand()%2 ==0){
            struct token_t t= create_simple_token(rand() %NUM_COLORS);
            all_tockens[i]=t;

        }
        else{
            unsigned int c[NUM_COLORS];
            c[rand()%NUM_COLORS]=1;
            c[rand()%NUM_COLORS]+=1;
            struct token_t t= create_complex_token(c);
            all_tockens[i]=t;

        }

    }
    return all_tockens;
}

struct guild init_guild(){
    struct guild guild;
    guild.nbr_builder= num_builder();
    struct builder_t* builder_in_guild[MAX_BUILDERS];
    for (int i=0; i< guild.nbr_builder;++i){

        guild.builder_in_guild[i]=&game_builders[i];
    }
}
struct market init_market(){
    struct market market;
    market.nbr_token=NUM_TOKENS;
    memset(market.available_tokens, 0, NUM_TOKENS); /*Initialiser à 0, 
    car tous les jetons appartiennet à la pioche au début du jeu*/
}


void init_tokens_from_builers(struct guild guild){
    for (int i=0; i< guild.nbr_builder; ++i){
        struct token_t tmp= create_simple_token(*(guild.builder_in_guild[i]).ressource.c);
        tmp[guild.builder_in_guild[i]->ressource.c]=guild.builder_in_guild[i]->ressource.n;
        tokens_from_builders[i]=tmp;
    }
    

}


  

int main(int argc, char* argv[]){   
    srand(SEED);
    if (argc < NB_MIN_PARAM){
        printf("there is a mistake");
        return EXIT_FAILURE;
    }

    //Init player
    struct player* current_player = get_random_player();

   
  


    //init market and guild    
    init_builders(0);   // Use seed 0 at the beginning of a game
    init_tokens(0);     // Same thing
    struct guild guild=init_guild(); // il faut initialiser les guild;
    struct market market=init_market();
    int nb_turns_not_played=0;
    int nb_turns=0;
    init_all_tokens(); //comment initialiser les tokens
    init_tokens_from_builers(guild);

    

    int possibility=0;

    while ((has_won(player1, player2) && nb_turns_not_played<2)&& nb_turns< MAX_TURN){
        int index;
        for (int i=0; i<guild.nbr_builder; i++){
            if(guild.builder_in_guild[i]){
                if (possibility_token_paytoken_pay(current_player->player_token, game_builders[i], market)){
                    possibility=1;
                    index=i;

        }
        }
    }
    if (possibility){
        //penser à implementer le fait que les tokens utilisés doivent être remis sur le marché
        current_player->player_token[index+ NUM_TOKENS-1]= &tokens_from_builders[index];

        // put in the market the tokens which were useful to pay the builder, except if they are builders
        token_pay(current_player->player_token, *guild.builder_in_guild[index], market);
        current_player->player_builder[current_player->nbr_builder]= guild.builder_in_guild[index];
        remove_builders_from_guild(guild, *guild.builder_in_guild[index]);

        //Add the ressource linked to the builder that we have added
        current_player->nbr_builder +=1;
        current_player->points= builder_points(current_player->player_builder[current_player->nbr_builder]) +current_player->points;
    }
    else{
        if(NUM_TOKENS - current_player->nbr_token){
            int nb=(NUM_TOKENS-current_player->nbr_token) % 3;
            int add=0;
            while (add<nb){
                int a =srand() % market.nbr_token;    if(NUM_TOKENS - current_player->nbr_token){
            int nb=(NUM_TOKENS-current_player->nbr_token) % 3;
            int add=0;
            while (add<nb){
                int a =srand() % market.nbr_token;
                if (market.available_tokens[a]){
                    current_player->player_token[current_player->nbr_token]=&all_tockens[a];
                    current_player->nbr_token= current_player->nbr_token +1;
                    market.available_tokens[a]=0;
                    add=add+1;
                }
            }
        }
        else {
                nb_turns_not_played= nb_turns_not_played+1;
            }
                if (market.available_tokens[a]){
                    current_player->player_token[current_player->nbr_token]=&all_tockens[a];
                    current_player->nbr_token= current_player->nbr_token +1;
                    market.available_tokens[a]=0;
                    add=add+1;
                }
            }
        }
        else {
                nb_turns_not_played= nb_turns_not_played+1;
            }
        }
    next_player(current_player);
}
    if(player1.points >= VICTORY_POINTS){
        printf("Victoire du joueur 1 avec %d points", player1.points);
    }
    if(nb_turns_not_played >= 2){
        printf("both loose");
    }
    else {
         printf("Victoire du joueur 2 avec %d points", player2.points);
    }
    return 0;
}
}