#include <stdio.h>
#include <math.h>
#define MAX 100

void ucitava(int a[], int dimenzija);
float aritmeticka_sredina_parnih(int a[], int dimenzija);
float kvadratna_sredina_neparnih(int a[], int dimenzija);

int main() {
    int n, niz[MAX], i;
    scanf("%d", &n);
    if (n<2 || n>MAX) {
        puts("-1");
        return 1;
    }
    ucitava(niz,n);
    printf("%.2f\n", aritmeticka_sredina_parnih(niz,n)+kvadratna_sredina_neparnih(niz,n));
//     printf("%.2f\n", aritmeticka_sredina_parnih(niz,n));
//     printf("%.2f\n", kvadratna_sredina_neparnih(niz,n));
}

void ucitava(int a[], int dimenzija) {
    int i;
    for (i=0; i<dimenzija; i++) {
        scanf("%d", &a[i]);
    }
    return;
}

float aritmeticka_sredina_parnih(int a[], int dimenzija) {
    int i, j=0;
    float suma=0;
    for (i=0; i<dimenzija; i+=2) {
        suma+=a[i];
        j++;
    }
    return suma/j;
}

float kvadratna_sredina_neparnih(int a[], int dimenzija) {
    int i, j=0;
    float suma=0;
    for (i=1; i<dimenzija; i+=2) {
        suma+=a[i]*a[i];
        j++;
    }
    return sqrt(suma/j);
}
