#include "token.h"
#include "color.h"
#include "builder.h"
#include <stdio.h>


struct player{
    struct token_t tab_token[NUM_TOKENS];
    struct builder_t tab_token[MAX_BUILDERS];
    int points;

};



int has_won(struct player player1, struct player player2){
    if (player1.points> =VICTORY_POINTS || player2.points>= VICTORY_POINTS){
        return 1
    }
    return 0;
}



int main(int argc, char* argv[]){
init_builders(0);   // Use seed 0 at the beginning of a game
init_tokens(0);     // Same thing
int nb_turns_not_played=0;
current_player = get_random_player();
struct player player1;
struct player player2;
while has_won(player1, player2){
    if current_player.wishes_to_hire():
        available_cards = guild.get_available_builders()
        a_builder = current_player.select_affordable_builder()
        current_player.hire_builder(a_builder);
    else:
        available_tokens = marken.get_available_tokens()
        current_player.pick_tokens(available_tokens);
    current_player = next_player(current_player);*/
}
}