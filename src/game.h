

struct market{
    int nbr_token;
    int available_tokens[NUM_TOKENS]; /*Le market est du type [0,1,3,...,NUM_COLORS] avec chaque position correspondant à la couleur d'un jeton*/

};

struct guild{
    int nbr_builder;
    struct builder_t* builder_in_guild[MAX_BUILDERS];

};


struct guild init_guild();
struct market init_market();

//Init NUM_TOKENS tokens
void init_tokens_from_builers();

//Pay the builder with the tokens of the player
void token_pay(struct builder_t*, struct player, struct market);

void remove_builders_from_guild(struct guild , struct buildcost_t );