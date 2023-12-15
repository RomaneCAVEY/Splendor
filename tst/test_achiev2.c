#include "test_achiev2.h"

struct guild guild;
struct market market;
struct player players[NB_PLAYERS]={};

int try_possibility_token_pay() {
    init_builders(0);
    players[0].favor_nbr=0;
    players[0].index=0;
    players[0].nbr_token=1;
    players[0].player_token[0]->s=create_specific_set();
    players[0].player_builder[0]=make_builder(0);
    players[0].nbr_builder=1;
    player_display(players[0]);
    printf("VOICI LE RESULTAT DE POSSIBILITY TOKEN PAY %d\n",possibility_token_pay(players[0],make_builder(1)));

}

//TEST A FINIR 

