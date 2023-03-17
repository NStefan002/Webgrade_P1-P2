#include <stdio.h>

void grafikon_v(int a, int b, int c, int d);

int main() {
    int o,p,q,r;
    printf("Unesite vrednosti: ");
    scanf("%d%d%d%d", &o,&p,&q,&r);
    if (o<0 || p<0 || q<0 || r<0) {
        printf("Greska: pogresan unos!\n");
        return 1;
    }
    grafikon_v(o,p,q,r);
}

void grafikon_v(int a, int b, int c, int d) {
    int i, j;
    int max=a;
    if (max<b) max=b;
    if (max<c) max=c;
    if (max<d) max=d;
    int maxp=max;
    for (i=0; i<max; i++) {
        for (j=0; j<1; j++) {
            if (a<maxp) printf(" ");
            else printf("*");
            if (b<maxp) printf(" ");
            else printf("*");
            if (c<maxp) printf(" ");
            else printf("*");
            if (d<maxp) printf(" ");
            else printf("*");
        }
        printf("\n");
        maxp--;
    }
}
