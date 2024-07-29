#include "showcard.h"
#include <stdio.h>
#include "cards.h"

int show_card(int a, int b, int c, int d, int *n){
    int m=(a%3+3)%3+1;
    printf("---- Player %d's round ----\n\n",m);
    printf("Last card: ");
    cards(b);
    printf("\nCurrent attack: %d",d);
    printf("\n\nPlayer %d's cards:\n",m);
    for (int i=0; i<c; i++) {cards(n[i]);}
    printf("\n\nInput n to play the (n+1)th card(input -1 to draw cards):");
    int k;
    if (scanf("%d", &k) == 1) {}
    if (k!=-1) {
        int q1=(n[k]-n[k]%13)/13;
        int q2=(b-b%13)/13;
        while (k > c - 1 || q1!=q2 && (n[k] - b) % 13 != 0) {
            printf("Invalid input! Please input again.\n");
            if (scanf("%d", &k) == 1) {}
        }
    }
    return k;
}
