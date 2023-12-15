#include "test_init.h"

struct set_t create_specific_set() {
    struct set_t set={};
    int complexe=0;
    printf("Token simple (0) ou complexe (1) ?\n");
    scanf("%d",&complexe);
    if(complexe){
        int c1=0;
        int c2=0;
        printf("Première couleur ? K: 0 B:1 G:2 R:3 W:4\n");
        scanf("%d",&c1);
        printf("Deuxième couleur ? K: 0 B:1 G:2 R:3 W:4\n");
        set.ressource[c1]=1;
        set.ressource[c2]=1;   
    }
    else{
        int c=0;
        printf("Quelle couleur ? K: 0 B:1 G:2 R:3 W:4\n");
        scanf("%d",&c);
        set.ressource[c]=1;
    }
    return set;
}

