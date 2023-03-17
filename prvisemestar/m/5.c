#include <stdio.h>

void grafikon_h(int a, int b, int c, int d);

int main() {
    int o,p,q,r;
    printf("Unesite vrednosti: ");
    scanf("%d%d%d%d", &o,&p,&q,&r);
    if (o<0 || p<0 || q<o || r<0) {
        printf("Greska: pogresan unos!\n");
        return 1;
    }
    grafikon_h(o,p,q,r);
}

void grafikon_h(int a, int b, int c, int d) {
    int i;
    for (i=0; i<a; i++) printf("*");
    printf("\n");
    for (i=0; i<b; i++) printf("*");
    printf("\n");
    for (i=0; i<c; i++) printf("*");
    printf("\n");
    for (i=0; i<d; i++) printf("*");
    printf("\n");
    return;
}
