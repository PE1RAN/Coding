#include "shuffle.h"
#include <stdlib.h>
#include <time.h>

void shuffle(int *n){
    srand(time(NULL));
    int test[52];
    int i,p;
    for (i=0;i<52;i++) {test[i]=1;}
    for (i=0;i<104;i++) {
        p=rand()%52;
        while (test[p]==-1) {p=rand()%52;}
        n[i]=p;
        test[p]=test[p]-1;
    }
}
