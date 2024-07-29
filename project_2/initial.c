#include "initial.h"
#include <stdio.h>

int initial_order(int a, int b, int c) {
    int min=a;
    int n;
    if (b<min) {min=b;}
    if (c<min) {min=c;}
    if (min==a) {printf("The game will start with player 1.\n\n"); n=1;}
    if (min==b) {printf("The game will start with player 2.\n\n"); n=2;}
    if (min==c) {printf("The game will start with player 3.\n\n"); n=3;}
    return n-1;
}
