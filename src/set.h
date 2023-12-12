 #ifndef __SET_H__
 #define __SET_H__
 #include "color.h"
 
struct set_t {
    unsigned int ressource[NUM_COLORS];
 };

/**
Display the content of the set
*/
void set_display(struct set_t set);



/**Creation of simple set*/
struct set_t create_simple_set(enum color_t c) ;


/**Creation of complex set*/
struct set_t create_complex_set(unsigned int c[NUM_COLORS]);


#endif