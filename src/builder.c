#include "builder.h"
#include "color.h"


/** Initializes the builders depending on an integer `seed`.
    Can be called multiple times. Can also do nothing. */
void init_builders(unsigned int seed){
    
}

/** Returns the total number of builders in the game. */
unsigned int num_builders();

/** Returns the `index`-th builder and NULL if it does not exist. */
struct builder_t* make_builder(unsigned int index);

/** Returns the level of the builder. */
unsigned int builder_level(const struct builder_t* g);

/** Returns the number of points of the builder. */
unsigned int builder_points(const struct builder_t* g);

/** Returns the cost that must be payed in order to hire this builder. */
struct buildcost_t builder_requires(const struct builder_t* g);

/** Returns the cost of the tokens that can be produced by this builder. */
struct buildcost_t builder_provides(const struct builder_t* g);

/** Displays the builder on the stdout, after a possible prefix.
    Example : builder_display(g, "    - ") displays on the screen :
    - Builder(lvl=1,cost=1W,prod=1B)
*/
void builder_display(const struct builder_t* g, const char* prefix);

#endif // __BUILDER_H__