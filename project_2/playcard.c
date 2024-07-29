#include "playcard.h"

void playcard(int a, int b, int c, int d, int e, int f, int* n, int* m) {
    c=n[d];
    for (int i=d;i<b-1;i++) {n[i]=n[i+1];}
    switch (c%13){
        case 0: a=a+2;break;
        case 1: a=a+3;break;
        case 9: f++;break;
        case 10: e=-1*e;break;
    }
    b--;
    m[0]=a;
    m[1]=c;
    m[2]=e;
    m[3]=f;
    m[4]=b;
}
