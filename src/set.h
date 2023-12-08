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
#endif