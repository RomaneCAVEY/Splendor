/** The number of tokens in play. */
#ifndef NUM_TOKENS
  #define NUM_TOKENS 25
#endif

/** The maximum level for a builder */
#ifndef NUM_LEVELS
  #define NUM_LEVELS 2
#endif

/** The maximum number of builders */
#ifndef MAX_BUILDERS
  #define MAX_BUILDERS 10
#endif


/** The maximum number of builders */
#ifndef VICTORY_POINTS
  #define VICTORY_POINTS 20
#endif




struct player{
    struct token_t* player_token[NUM_TOKENS+MAX_BUILDERS];
    struct builder_t* player_builder[MAX_BUILDERS];
    int points;
    int nbr_token;
    int nbr_builder;

};



int has_won(struct player, struct player);



struct player* get_random_player();

void next_player(struct player* );

