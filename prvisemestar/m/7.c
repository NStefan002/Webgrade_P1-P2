#include <stdio.h>

int prestupna(int godina);

int main() {
    int g1, g2, r=0;
    printf("Unesite dve godine: ");
    scanf("%d%d", &g1, &g2);
    if (g1>g2 || g1*g2<0) {
        printf("Greska!\n");
        return 1;
    }
    for (int i=g1; i<=g2; i++) {
        if (prestupna(i)) {
        r++;
        }
    }
    if(r==0) {
        printf("Nema!\n");
        return 0;
    }
    printf("Prestupne godine su: ");
    for (int i=g1; i<=g2; i++) {
        if (prestupna(i)) {
        printf("%d ", i);
        }
    }
    
}

int prestupna(int godina) {
    if ((godina%4==0 || godina%400==0) && godina%100!=0) return 1;
    else return 0;
}
