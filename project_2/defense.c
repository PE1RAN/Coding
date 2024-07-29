#include "defense.h"
#include <stdio.h>
#include "cards.h"

void defense(int a, int b, int c, int d, int e, int f, int *n, int* q, int* p){
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
    if (k==-1) {
        for (int j=c; j<c+d; j++) {n[j]=p[f];f++;}
        c=c+d;
        d=0;
    }
    else if (k!=-1) {
        int q1=(n[k]-n[k]%13)/13;
        int q2=(b-b%13)/13;
        while (k > c - 1 || (q1!=q2 > 12 && (n[k] - b) % 13 != 0) || (n[k] % 13 != 0 &&n[k] % 13 != 1 && n[k] % 13 != 5 && n[k] % 13 != 9 && n[k] % 13 == 10)) {
            printf("Invalid input! Please input again.\n");
            if (scanf("%d", &k) == 1) {}
        }
        b = n[k];
        for (int i = d; i < b - 1; i++) { n[i] = n[i + 1]; }
        switch (c % 13) {
            case 0:
                d = d + 2;
                break;
            case 1:
                d = d + 3;
                break;
            case 5:
                d = 0;
                break;
            case 9:
                a++;
                break;
            case 10:
                e = -1 * e;
                break;
        }
        c--;
    }
    q[0]=a;
    q[1]=b;
    q[2]=c;
    q[3]=d;
    q[4]=e;
    q[5]=f;
}
