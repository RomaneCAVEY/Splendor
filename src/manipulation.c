#include "token.h"

#include "builder.h"

#include "color.h"

#include <stdio.h>

#include <stdlib.h>


/*return 0 if the token is simple and 1 otherwise*/
int is_complex(struct token_t * t) {
    int count = 0;
    for (int i = 0; i < NUM_COLORS; ++i) {
        count = count + t -> c[i];
        if (count > 1) return 1;
    }
    return 0;

}